cmake_minimum_required(VERSION 3.10)

add_executable(main main.c)

set_target_properties(main
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#main depends on hello.h, so we need to tell it where to find it
include_directories(hello)

# descend into the hello directory to trigger CMakeLists.txt there
add_subdirectory(hello)

#link main with the HELLO library
target_link_libraries(main HELLO)
#"${CMAKE_BINARY_DIR}/lib/HELLO")
