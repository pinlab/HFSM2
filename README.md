[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![GitHub Release Date](https://img.shields.io/github/release-date/andrew-gresyk/HFSM2)](https://github.com/andrew-gresyk/HFSM2/releases)  
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/andrew-gresyk/HFSM2.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/andrew-gresyk/HFSM2/context:cpp)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/5335/badge)](https://bestpractices.coreinfrastructure.org/projects/5335)  
[![GCC, Clang](https://github.com/andrew-gresyk/HFSM2/actions/workflows/cmake.yml/badge.svg)](https://github.com/andrew-gresyk/HFSM2/actions/workflows/cmake.yml)
[![ARM GCC](https://github.com/andrew-gresyk/HFSM2/actions/workflows/cmake-qemu-arm.yml/badge.svg)](https://github.com/andrew-gresyk/HFSM2/actions/workflows/cmake-qemu-arm.yml)
[![MS VS](https://github.com/andrew-gresyk/HFSM2/actions/workflows/msbuild.yml/badge.svg)](https://github.com/andrew-gresyk/HFSM2/actions/workflows/msbuild.yml)  
[![Gitter](https://badges.gitter.im/andrew-gresyk/HFSM2.svg)](https://gitter.im/andrew-gresyk/HFSM2)
[![Discord](https://img.shields.io/discord/591914197219016707.svg?label=&logo=discord&logoColor=ffffff&color=7389D8&labelColor=6A7EC2)](https://discord.gg/ujpNbqSpfm)
[![Twitter Follow](https://img.shields.io/twitter/follow/andrew_gresyk?style=social)](https://www.twitter.com/andrew_gresyk)

---

![HFSM2](assets/logos/hfsm2-logo-large.png)

# High-Performance Hierarchical Finite State Machine

Header-only heriarchical FSM framework in C++11, with fully statically-defined structure (no dynamic allocations), built with variadic templates.

---

## Compiler Support

- Visual Studio: **2015, 2017, 2019**
- GCC: **5, 6, 7, 8, 9, 10, 11**
- ARM GCC: **9**
- Clang: 3.7, 3.8, 3.9, 4, 5, 6, 7, 8, **9, 10, 11**
- AppleClang: **12, 13**

(Currently CI-tested in **bold**)

---

## Quick Start

- **[Tutorial](examples/snippets/wiki_tutorial.cpp)**

---

## See Also

- **[FFSM2](https://flat.hfsm.dev)**: High-Performance **Flat** Finite State Machine

---

## Documentation

- GitBook: **[doc.hfsm.dev](https://doc.hfsm.dev/)** (WIP)
- Wiki: **[Tutorial](https://github.com/andrew-gresyk/HFSM2/wiki/Tutorial)** (Obsolete)
- In-line comments

---

## Feature Highlights

- Permissive **[MIT License](LICENSE)**
- Written in widely-supported modern(ish) C++11
- Header-only
- Convenient, minimal boilerplate
- Fully static, no dynamic allocations
- Uses inline-friendly compile-time polymorphism, no virtual methods are used
- Type-safe transitions: `FSM.changeTo<TargetState>()` with optional payloads
- Scaleable, supports robust state re-use via state injections
- **[Hierarchical](https://github.com/andrew-gresyk/HFSM2/wiki/Transitions-within-Hierarchy)**, with a selection of composite (sub-machine) and orthogonal regions
- Gamedev-friendly, supports explicit `State::update()`
- Also supports traditional event-based workflow with `State::react()`
- Inspect anything: previous and current transitions, state activation status, and more!
- Game AI-friendly with **[dynamic planning](https://github.com/andrew-gresyk/HFSM2/wiki/Plans)** support
- **[Utility theory](https://github.com/andrew-gresyk/HFSM2/wiki/Utility-Theory)** support (max score and ranked weighted random)
- **[Serializable](https://doc.hfsm.dev/user-guide/debugging-and-tools/serialization)**, with activity and transition history support
- **[Debug-assisted](https://gresyk.dev/features/2018/01/15/hfsm-magic.html)**, includes automatic structure and activity visualization API with `#define HFSM_ENABLE_STRUCTURE_REPORT`
- Built-in logging support

---

## 3rd Party Libraries

- **[doctest](https://github.com/onqtam/doctest)** unit testing framework
- **[XoShiRo](http://xoshiro.di.unimi.it/)** pseuto-random number generators

---

## Get In Touch

- Twitter: **[@andrew_gresyk](https://www.twitter.com/andrew_gresyk)**
- Discord: **[HFSM.dev](https://discord.gg/v4t3tzh)**
- Gitter: **[andrew-gresyk/HFSM2](https://gitter.im/andrew-gresyk/HFSM2)**

---

## Special Thanks

- [alexandrosk0](https://github.com/alexandrosk0)
- [DJuego](https://github.com/DJuego)
- [Kevin Greene](https://github.com/kgreenek)
- [Kjeld Mathias Petersen](https://github.com/DonMathi)
- Mehdi Houshmand
- [mrcmry](https://github.com/mrcmry)
- [Phil Nash](https://github.com/philsquared)
- [Romain Cheminade](https://github.com/romaincheminade)
- [Tristan Brindle](https://github.com/tcbrindle)
- [C++::London](https://www.meetup.com/CppLondon/) meetup
- programming community at [Splash Damage](http://www.splashdamage.com/)
