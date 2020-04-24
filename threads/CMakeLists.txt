cmake_minimum_required(VERSION 3.10)
project(threads)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(threads main.cpp)