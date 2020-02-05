cmake_minimum_required(VERSION 3.10)

add_library(HELLO SHARED hello.c hello.h)
install(TARGETS HELLO DESTINATION "/usr/lib")
