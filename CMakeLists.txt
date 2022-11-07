cmake_minimum_required(VERSION 3.0)

project(Sheet)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_executable(testSheet testSheet.cpp src/BPlusTree.cpp src/Sheet.cpp)