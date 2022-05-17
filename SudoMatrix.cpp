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

void SudoMatrix::fillMatrix() {
    int toReplace = rand() % 9 + 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            toReplace = rand() % 9 + 1;
            while (!checkIndex(i,j,toReplace)) {
                toReplace++;
                if (toReplace > 9) {
                    toReplace = 1;
                }
            }
            matrix[i][j] = toReplace;
            }
    }
}

bool SudoMatrix::checkIndex(int row, int column, int target) {
    if (checkRow(row, target) && checkCol(column, target)) {
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
    int Xbox = row/2
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