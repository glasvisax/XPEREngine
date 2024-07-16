cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(XPEREngine)

if(EXISTS "${CMAKE_SOURCE_DIR}/LocalPaths.cmake")
  include("${CMAKE_SOURCE_DIR}/LocalPaths.cmake")
else()
  message(WARNING "LocalPaths.cmake file not found. Default paths will be used.")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${THOR_MODULE})

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
find_package(Thor 2 MODULE REQUIRED)
find_package(GTest CONFIG REQUIRED)

add_subdirectory(Tests Tests/build)
add_subdirectory(Engine Engine/build)
