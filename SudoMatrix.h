//
// Created by Max on 2022-05-10.
//

#ifndef SUDOKU_SUDOMATRIX_H
#define SUDOKU_SUDOMATRIX_H
#include "Matrix.h"
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
    Matrix r1c1;
    Matrix r1c2;
    Matrix r1c3;
    Matrix r2c1;
    Matrix r2c2;
    Matrix r2c3;
    Matrix r3c1;
    Matrix r3c2;
    Matrix r3c3;
public:
    vector<vector<Matrix>> SudoMap {
            {r1c1, r1c2, r1c3},
            {r2c1, r2c2, r2c3},
            {r3c1, r3c2, r3c3}
    };
    SudoMatrix(){};
    void printSudo() {
        for (int i = 0; i < 3; i++) {

        }
    }
};


#endif //SUDOKU_SUDOMATRIX_H
