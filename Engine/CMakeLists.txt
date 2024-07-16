cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Engine)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

add_executable(Main ${SOURCES})

target_link_libraries(Main PRIVATE sfml-system PRIVATE sfml-window PRIVATE sfml-graphics PRIVATE sfml-audio PRIVATE ${THOR_LIBRARY})
target_include_directories(Main PUBLIC ${THOR_INCLUDE_DIR})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src FILES ${SOURCES})
