cmake_minimum_required(VERSION 3.10)

project(C_Data_Structures_and_Algorithms)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(ArrayList src/ArrayList.c)

add_executable(test_arraylist test/test_arraylist.c)
target_link_libraries(test_arraylist ArrayList)
