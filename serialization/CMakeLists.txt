cmake_minimum_required(VERSION 3.10)
project(serialization)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/cereal/include)

add_executable(serialization main.cpp)