cmake_minimum_required(VERSION 3.13)
project(generator)

set(CMAKE_CXX_STANDARD 17)

add_executable(generator main.cpp room.hpp door.hpp spot.hpp generator.hpp position.hpp)