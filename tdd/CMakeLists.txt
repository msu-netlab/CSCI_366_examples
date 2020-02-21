cmake_minimum_required(VERSION 3.10)
project(tdd)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)

add_subdirectory(test)

add_executable(tdd main.cpp src/Rectangle.cpp src/include/Rectangle.h)