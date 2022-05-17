//
// Created by Max on 2022-05-10.
//

#ifndef SUDOKU_SUDOMATRIX_H
#define SUDOKU_SUDOMATRIX_H
#include "vector"
#include "algorithm"
#include "math.h"
#include "iostream"
#include "stdlib.h"
using namespace std;
/**
 *    1 2 3   4 5 6   7 8 9
 *    ---------------------
 * 1  x x x | x x x | x x x
 * 2  x x x | x x x | x x x
 * 3  x x x | x x x | x x x
 *   ---------------------
 * 4  x x x | x x x | x x x
 * 5  x x x | x x x | x x x
 * 6  x x x | x x x | x x x
 *   ---------------------
 * 7  x x x | x x x | x x x
 * 8  x x x | x x x | x x x
 * 9  x x x | x x x | x x x
 *
 * */
class SudoMatrix {
    vector<vector<int>> matrix;
    int size;
    int boxSize;
public:
    SudoMatrix(){};
    SudoMatrix(int size);
    void printSudo() {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j];
                if ((j+1)%boxSize == 0) {
                    cout << "|";
                }
            }
            cout << endl;
        }
    }
    void fillMatrix();
    bool checkRow(int row, int target);
    bool checkCol(int column, int target);
    bool checkBox(int row, int column, int target);
    bool checkIndex(int row, int column, int target);
    void setValue(int row, int column, int target);
};


#endif //SUDOKU_SUDOMATRIX_H
