cmake_minimum_required(VERSION 3.10)
project(NASM)
enable_language(ASM_NASM)

set_source_files_properties(examples.asm PROPERTIES COMPILE_FLAGS "-g -Fdwarf")
set_source_files_properties(get_2D_array_element.asm PROPERTIES COMPILE_FLAGS "-g -Fdwarf")
set_source_files_properties(get_2D_vector_element.asm PROPERTIES COMPILE_FLAGS "-g -Fdwarf")
set_source_files_properties(get_rect_area.asm PROPERTIES COMPILE_FLAGS "-g -Fdwarf")

set(CMAKE_CXX_STANDARD 11)

add_executable(main examples.asm
        get_2D_array_element.asm
        get_2D_vector_element.asm
        get_rect_area.asm
        main.cpp)
