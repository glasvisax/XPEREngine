cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TESTS)

file(GLOB_RECURSE TEST_SOURCES "src/*.cpp" "src/*.h")

add_executable(Tests ${TEST_SOURCES})

target_link_libraries(Tests PRIVATE GTest::gtest_main)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

target_include_directories(Tests PUBLIC "../Engine/src")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src FILES ${TEST_SOURCES})