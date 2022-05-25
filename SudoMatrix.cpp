//
// Created by Max on 2022-05-10.
//

#include "SudoMatrix.h"
SudoMatrix::SudoMatrix(int size) {
    this->size = size;
    boxSize = sqrt(size);
    for (int i = 0; i < size; i++) {
        matrix.push_back(vector<int>{});
        for (int j = 0; j < size; j++) {
            matrix[i].push_back(0);
        }
    }
}

void SudoMatrix::prefillDiagonal() {
    fillSubmatrix(0,0, true);
    fillSubmatrix(3,3, true);
    fillSubmatrix(6,6, true);
}

void SudoMatrix::fillSubmatrix(int xStart, int yStart, bool diagonal) {
    int next = rand() % 9 + 1;
    for (int row = xStart; row < (xStart + boxSize); row++) {
        for (int col = yStart; col < (yStart + boxSize); col++) {
            if (diagonal) {
                while (!checkBox(xStart, yStart, next)) {
                    next = rand() % 9 + 1;
                }
            } else {
                while (!checkIndex(row, col, next)) {
                    next = rand() % 9 + 1;
                }
            }
            matrix[row][col] = next;
        }
    }
}


bool SudoMatrix::fillMatrix(int row, int column) {
    if (row >= matrix.size()) {
        return true;
    }
    if (column>=size) {
        row++;
        column = 0;
    }
    if (matrix[row][column]) {
        if (column != (size-boxSize)) {
            column += boxSize;
        } else {
            row++;
            column = 0;
            if (row >= matrix.size()) {
                return true;
            }
        }
    }
    int random = rand() % 9 + 1;

    for (int i = 0; i < size; i++) {
        if (random > size) {
            random = 1;
        }
        if (checkIndex(row, column, random)) {
            matrix[row][column] = random;
            if (fillMatrix(row, column+1)) {
                return true;
            }
            matrix[row][column] = 0; //Backtrack
        }
        random++;
    }

    return false;
}


bool SudoMatrix::checkIndex(int row, int column, int target) {
    if (checkRow(row, target) && checkCol(column, target) && checkBox(row, column, target)) {
        return true;
    }
    return false;
}

bool SudoMatrix::checkRow(int row, int target) {
    //CheckRow
    for (int i = 0; i < size; i++) {
        if (matrix[row][i] == target) {
            return false;
        }
    }
    return true;
}

bool SudoMatrix::checkBox(int row, int column, int target) {
    int Xbox = (row/boxSize) * boxSize;
    int Ybox = (column/boxSize) * boxSize;
    for (int r = Xbox; r < (Xbox + boxSize); r++) {
        for (int c = Ybox; c < (Ybox + boxSize); c++) {
            if (matrix[r][c] == target) {
                return false;
            }
        }
    }
    return true;
}

bool SudoMatrix::checkCol(int column, int target) {
    for (int j = 0; j < size; j++) {
        if (matrix[j][column] == target) {
            return false;
        }
    }
    return true;
}

void SudoMatrix::setValue(int row, int column, int target) {
    if (row > matrix.size() || row < 1 || column > matrix[0].size() || column < 1) {
        cerr << "SudoMatrix: Setting value out of bounds!" << endl;
        return;
    }
    matrix[row-1][column-1] = target;
}