cmake_minimum_required(VERSION 3.0)

project(testmain)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_COMPILE_FEATURES "/usr/bin/g++")

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/include)

link_libraries(pthread)
# add_library(library_name STATIC
# src/Sheet.cpp  src/CLThread.cpp  src/BPlusTree.cpp include/BPlusTree.h include/CLExecutive.h include/CLExecutiveFunctionProvider.h include/CLFindValue.h include/CLInsertPiece.h include/CLThread.h include/node.h include/piece.h include/Sheet.h)

#add_executable(finalTest  src/BPlusTree.cpp src/Sheet.cpp src/CLThread.cpp mainTest.cpp  )
#add_executable(finalTest   src/BPlusTree.cpp  src/Sheet.cpp  src/CLThread.cpp src/CLInsertPiece.cpp src/CLFindValue.cpp mainTest.cpp)
add_executable(finalTest   src/BPlusTree.cpp  src/Sheet.cpp  src/CLThread.cpp  mainTest.cpp)
# target_link_libraries(finalTest library_name)

