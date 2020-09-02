cmake_minimum_required(VERSION 3.10.2)

project(2048cpp-game)

include_directories(includes)
file(GLOB SOURCES "src/*.cpp")
add_library(sqlite3 STATIC libraries/sqlite/sqlite3.c libraries/sqlite/sqlite3.h)

add_executable(2048cpp ${SOURCES})

target_link_libraries(2048cpp sqlite3 dl pthread)