# 2048.cpp
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/6070e347d955450b8724bcff94c1be64)](https://www.codacy.com/manual/mgirardin/2048.cpp?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=mgirardin/2048.cpp&amp;utm_campaign=Badge_Grade)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/mgirardin/2048.cpp.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/mgirardin/2048.cpp/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/mgirardin/2048.cpp.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/mgirardin/2048.cpp/context:cpp)

Fully configurable CLI version of the game 2048


## Demo

![2048 Demo](assets/readme/2048.gif)

## Setup

### Requirements

* C++11 compiler (e.g. `g++`)
* Unix environment (for now)
* CMake

### Build

1. Clone this project
```sh
git clone https://github.com/mgirardin/2048.cpp.git
```
2. Enter the project's build directory (or create one):
```sh
cd 2048.cpp/build
```
3. Generate Makefile 
```sh
cmake ..
```
4. Build
```sh
make
```
5. Run the program
```sh
./2048cpp
```
