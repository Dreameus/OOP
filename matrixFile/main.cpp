#include <iostream>
#include <fstream>
#include <random>
#include "matrix.h"

int main()
{
    std::ofstream file("output.txt");

    matrix mat(10, 10);
    mat.init();

    if (file.is_open()) 
    { 
        file << mat;
    }
    else
    {
        std::cout << "Error opening file!" << std::endl;
    }

    return 0;
}