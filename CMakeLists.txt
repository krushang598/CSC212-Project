cmake_minimum_required (VERSION 3.0)

project (Maze_BST)

set(HEADER_FILES Maze_BST.h)
add_library(Maze_BST Maze_BST.cxx ${HEADER_FILES}) 
add_executable(main main.cxx ${HEADER_FILES})
target_link_libraries(Maze_BST)
target_compile_options(main PRIVATE -std=c++0x -g -Wall)
