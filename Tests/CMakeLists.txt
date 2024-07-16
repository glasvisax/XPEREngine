cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TESTS)

file(GLOB_RECURSE TEST_SOURCES "src/*.cpp" "src/*.h" "../Engine/src/*.cpp" "../Engine/src/*.h")

add_executable(Tests ${TEST_SOURCES})

target_link_libraries(Tests PRIVATE GTest::gtest_main)
