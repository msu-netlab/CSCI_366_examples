# Basic CMake example
# Tasks:
# - set up source and build directories
# - CMake is smart enough to figure out dependency on hello.h

cmake_minimum_required(VERSION 3.10)

project(hello)

add_executable(main main.c hello.c)
