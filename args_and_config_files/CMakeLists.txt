cmake_minimum_required(VERSION 3.10)
project(args_and_config_files)

set(CMAKE_CXX_STANDARD 14)

# set up yaml
add_subdirectory(yaml-cpp)
#execute_process(COMMAND make WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/yaml-cpp)
include_directories(yaml-cpp/include)


# move config.yaml into the build directory
configure_file(${PROJECT_SOURCE_DIR}/config.yaml ${PROJECT_BINARY_DIR}/config.yaml COPYONLY)

add_executable(args_and_config_files main.cpp)
target_link_libraries(args_and_config_files ${PROJECT_BINARY_DIR}/yaml-cpp/libyaml-cppd.a)
