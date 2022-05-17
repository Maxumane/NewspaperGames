#include <iostream>
#include "SudoMatrix.h"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    SudoMatrix SM(9);
    SM.fillMatrix();
    SM.printSudo();
    return 0;
}
