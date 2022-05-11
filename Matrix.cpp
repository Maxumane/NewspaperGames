//
// Created by Max on 2022-05-09.
//

#include <iostream>
#include <algorithm>
#include "Matrix.h"
#include "random"
Matrix ::Matrix() {
    auto rng = std::default_random_engine {};
    std::shuffle(numbers.begin(), numbers.end(), rng);
}

void Matrix ::printMatrix() {
    cout << "Printing" << endl;
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            cout << numbers[(i*3) + j];
        }
        cout << endl;
    }
}

int Matrix::returnVal(int col, int row) {

}

