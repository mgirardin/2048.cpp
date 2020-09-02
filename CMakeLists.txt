cmake_minimum_required(VERSION 3.10.2)

# set the project name
project(2048cpp)

include_directories(includes)
file(GLOB SOURCES "src/*.cpp")

# add the executable
add_executable(2048cpp ${SOURCES})