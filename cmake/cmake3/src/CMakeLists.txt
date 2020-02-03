cmake_minimum_required(VERSION 3.10)

add_executable(main main.c hello.c) 

set_target_properties(main
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

