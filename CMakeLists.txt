cmake_minimum_required(VERSION 3.0)

project(BplusTree)

set(CMAKE_BUILD_TYPE Debug)

add_executable(testBPlusTree testBPlusTree.cpp BPlusTree.cpp)