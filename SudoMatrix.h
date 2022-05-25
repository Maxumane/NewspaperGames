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

public:
    int size;
    int boxSize;
    SudoMatrix(){};
    SudoMatrix(int size);
    void printSudo() {
        cout << "   A B C|D E F|G H I" << endl;
        cout << "  -------------------" << endl;
        for (int i = 0; i < matrix.size(); i++) {
            cout << i+1 << " |";
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j];
                if ((j+1)%boxSize == 0) {
                    cout << "|";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
            if ((i+1)%boxSize == 0) {
                cout << "  -------------------" << endl;
            }
        }
    }
    void initialize() {
        prefillDiagonal();
        fillMatrix(0, boxSize);
        printSudo();
        //Start collecting player input
    }
    bool fillMatrix(int i, int j);
    bool checkRow(int row, int target);
    bool checkCol(int column, int target);
    bool checkBox(int row, int column, int target);
    bool checkIndex(int row, int column, int target);
    void setValue(int row, int column, int target);
    void prefillDiagonal();
    void fillSubmatrix(int Xstart, int Ystart, bool diagonal);
};


#endif //SUDOKU_SUDOMATRIX_H
