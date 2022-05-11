//
// Created by Max on 2022-05-09.
//
#include "stdlib.h"
#include "vector"
#ifndef SUDOKU_MATRIX_H
#define SUDOKU_MATRIX_H
using namespace std;

class Matrix {
public:
    vector<int> numbers
            {
                    {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9}
            };
    void printMatrix();
    int returnVal(int col, int row);
    Matrix();
    Matrix(vector<int> input);
};


#endif //SUDOKU_MATRIX_H
