add_executable(tdd_tests tests.cpp ../src/Rectangle.cpp ../src/include/Rectangle.h MockRectangle.h)

include_directories(${PROJECT_SOURCE_DIR}/src/include)

target_link_libraries(tdd_tests gtest gmock_main)