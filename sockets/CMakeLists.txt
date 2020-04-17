cmake_minimum_required(VERSION 3.10)
project(sockets)

set(CMAKE_CXX_STANDARD 14)

add_executable(echo_server echo_server.cpp)

add_executable(echo_client echo_client.cpp)

