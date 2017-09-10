cmake_minimum_required(VERSION 3.8)
project(tarea)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Bubblesort.h Insertionsort.h "AVL Tree.h" Mergesort.h Selectionsort.h)
add_executable(tarea ${SOURCE_FILES})