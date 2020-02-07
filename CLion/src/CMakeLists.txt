cmake_minimum_required(VERSION 3.10)

add_executable(main main.c)

include_directories(hello)

add_subdirectory(hello)

target_link_libraries(main HELLO)
