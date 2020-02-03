# CMake example with directories
# Tasks:
# - build the executable > cmake .; cmake --build .

cmake_minimum_required(VERSION 3.10)

project(hello)

add_executable(main src/main.c src/hello.c)

set_target_properties(main
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
