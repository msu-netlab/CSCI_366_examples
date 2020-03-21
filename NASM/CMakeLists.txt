cmake_minimum_required(VERSION 3.10)
project(NASM)
enable_language(ASM_NASM)

set_source_files_properties(examples.asm PROPERTIES COMPILE_FLAGS "-g -Fdwarf")

set(CMAKE_CXX_STANDARD 11)

add_executable(main examples.asm main.cpp)
