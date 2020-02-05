# CMake example with directories
# Tasks:
# - add sources with a wildcard file(GLOB SOURCES src/*.c)

cmake_minimum_required(VERSION 3.10)

project(hello)

add_executable(main src/main.c src/hello.c)

set_target_properties(main
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin"
)
