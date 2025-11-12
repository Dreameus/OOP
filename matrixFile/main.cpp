#include <iostream>
#include <fstream>
#include "matrix.h"
#include "functions.h"

int main()
{
    std::string name = "output.txt";

    matrix mat(name);

    std::cout << mat;

    

    return 0;
}
