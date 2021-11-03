cmake_minimum_required(VERSION 3.5)

project(event_loop C CXX)

find_package(Threads)

add_executable(event_loop main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/../../external"
        "${CMAKE_CURRENT_LIST_DIR}/../../include"
        )

target_link_libraries(${PROJECT_NAME} Threads::Threads)
