cmake_minimum_required(VERSION 3.17)
project(Sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sudoku main.cpp SudoMatrix.cpp SudoMatrix.h SpellingBee.cpp SpellingBee.h Dictionary.h words.txt)