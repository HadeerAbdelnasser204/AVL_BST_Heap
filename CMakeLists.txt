cmake_minimum_required(VERSION 3.24)
project(DS)

set(CMAKE_CXX_STANDARD 17)

add_executable(DS main.cpp MinHeap.h MinHeap.cpp MaxHeap.h MaxHeap.cpp)
