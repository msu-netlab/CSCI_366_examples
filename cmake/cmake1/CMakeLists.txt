# Basic CMake example
# Tasks:
# - set up source and build directories

cmake_minimum_required(VERSION 3.10)

project(hello)

add_executable(main main.c hello.c)
