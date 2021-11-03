// Creates a class for event loop
// Creates a series of time delayed events.
//

//#define HFSM2_ENABLE_VERBOSE_DEBUG_LOG
#include <iostream>
#include <vector>

#include <hfsm2/machine.hpp>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <chrono>

// FSM with 3 states (A) -> (B) -> (C)
using FSM = hfsm2::Machine::PeerRoot<
        struct A,
        struct B,
        struct C
>;

struct ReqEvent {
    char target{0};
};

struct A: FSM::State{
    void react(const ReqEvent& ev, FullControl& control){
        switch (ev.target) {
            case 'b': control.changeTo<B>(); break;
        }
    }
};
struct B: FSM::State{
    void react(const ReqEvent& ev, FullControl& control){
        switch (ev.target) {
            case 'c': control.changeTo<C>(); break;
        }
    }
};

struct C: FSM::State{
    void react(const ReqEvent& ev, FullControl& control){
        switch (ev.target) {
            case 'a': control.changeTo<A>(); break;
        }
    }
};

template<typename FsmT>
constexpr char GetActiveState(const typename FsmT::Instance instance){
    if(instance.template isActive<A>()) return 'A';
    if(instance.template isActive<B>()) return 'B';
    if(instance.template isActive<C>()) return 'C';
    return '?';
}

template<typename FsmT, typename E>
class FsmEventDispatcher{
public:
    void push(const E& event){
        std::lock_guard<std::mutex> lock(mtx_);
        if(!aborted_ ){
            events_.push_back(event);
            cv_.notify_one();
        }
    }

    void abort(){
        std::lock_guard<std::mutex> lock(mtx_);
        aborted_ = true;
        cv_.notify_one();
    }

    void run(){
        while(true){
            std::unique_lock<std::mutex> lock (mtx_);
            cv_.wait(lock, [this]{return this->aborted_ || !events_.empty();});
            if (aborted_) break;
            const auto& ev = events_.front();
            std::cout << GetActiveState<FsmT>(instance_);
            instance_.react(ev);
            std::cout << " -- " << (ev.target) << " --> " << GetActiveState<FsmT>(instance_) << std::endl;
            events_.pop_front();
        }
    }

private:
    typename FsmT::Instance instance_;
    bool aborted_ {false};
    std::mutex mtx_;
    std::condition_variable cv_;
    std::deque<E> events_;
};


int main(){
    FsmEventDispatcher<FSM, ReqEvent> proc;
    std::thread loop(&FsmEventDispatcher<FSM, ReqEvent>::run, &proc);

    // dispatch a some timed events in threads - holding lambda
    int n = 10;
    std::vector<std::thread> threads;
    threads.reserve(n);
    for(int i = 0; i < n; ++i) {
        // rand -> quick'n'dirty
        threads.emplace_back(
                [&proc, i] {
                    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
                    char ev = i % 3 == 0 ? 'b' : i % 3 == 1 ? 'c' : 'a';
                    proc.push(ReqEvent{ev});
                }
        );
    }
    // join all thread
    for(auto& t : threads){
        t.join();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
    proc.abort();
    loop.join();
    std::cout << "DONE" << std::endl;
}

