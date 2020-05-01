cmake_minimum_required(VERSION 3.10)
project(sqlite)

set(CMAKE_CXX_STANDARD 14)

# copy over the company database to the build folder
configure_file(${PROJECT_SOURCE_DIR}/company.sqlite ${PROJECT_SOURCE_DIR}/cmake-build-debug/company.sqlite COPYONLY)

# include the headers for the sqlite C++ wrapper
include_directories(sqlite_modern_cpp/hdr)

# compile the executable
add_executable(sqlite main.cpp)

# include the sqlite3 library
# needs to be installed on Ubuntu via
# $ sudo apt install libsqlite3-dev
include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(sqlite sqlite3)


