#include <iostream>
#include "SudoMatrix.h"

#include <bits/stdc++.h>
using namespace std;

int main()
{
/*    cout << 5/3 << " " << 5%3;*/
    SudoMatrix SM(9);
    SM.fillMatrix();
    SM.printSudo();
    return 0;
}
