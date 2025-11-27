#include <iostream>
#include <random>
#include "matrix.h"

int main()
{
    matrix mat1(3, 3);
    matrix mat2(3, 3);
    matrix mat3(3, 3);

    std::cout << matrix::getCount() << std::endl;
    
    return 0;
}