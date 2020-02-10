cmake_minimum_required(VERSION 3.10)
project(args_and_config_files)

set(CMAKE_CXX_STANDARD 14)

# set up yaml
add_subdirectory(yaml-cpp)
include_directories(yaml-cpp/include)

# build yaml
# !!! go into cmake-build-debug/yaml-cpp in your terminal and call make
# the call below goes into a infinite loop - if you can solve this I'll give you mad props
#execute_process(COMMAND touch out.txt WORKING_DIRECTORY )

# move config.yaml into the build directory
configure_file(${PROJECT_SOURCE_DIR}/config.yaml ${PROJECT_BINARY_DIR}/config.yaml COPYONLY)

add_executable(args_and_config_files main.cpp)
target_link_libraries(args_and_config_files ${PROJECT_BINARY_DIR}/yaml-cpp/libyaml-cppd.a)

