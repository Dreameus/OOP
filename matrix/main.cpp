#include <iostream>
#include <random>
#include "matrix.h"

int main()
{
    matrix mat(10, 10);
    mat.init();
    matrix mat1(10,10);
    mat1.initRandom();

    mat1 = mat1 * mat;

    std::cout << mat1 << std::endl;

    mat1++;

    std::cout << mat1 << std::endl;

    return 0;
}