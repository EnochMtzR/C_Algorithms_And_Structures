cmake_minimum_required(VERSION 3.22)

project(AlgorithmsAndDataStructures)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

enable_testing()


add_library(algorithms src/algorithms.c)

add_executable(testAlgorithms test/test_algorithms.cpp)

target_link_libraries(testAlgorithms algorithms gtest gtest_main)

add_test(NAME testAlgorithms COMMAND testAlgorithms)


add_library(strings src/Strings/String.c)

