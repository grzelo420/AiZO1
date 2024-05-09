cmake_minimum_required(VERSION 3.25)
project(SDIZO)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDIZO main.cpp Heap.cpp Table.cpp RedBlackTree.cpp Testing.h Testing.cpp DataGenerator.h DataGenerator.cpp LinkedList.h LinkedList.cpp)
