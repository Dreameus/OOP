#include <iostream>
#include <random>
#include "matrix.h"

matrix::matrix(int rows, int cols)
{
    this->rows_m = rows;
    this->cols_m = cols;

    mat_m = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        mat_m[i] = new int[cols];
    }
}

matrix::matrix(const matrix& other)
{
    rows_m = other.rows_m;
    cols_m = other.cols_m;

    mat_m = new int*[rows_m];

    for(int i = 0; i < rows_m; i++)
    {
        mat_m[i] = new int[cols_m];

        for(int j = 0; j < cols_m; j++)
        {
            mat_m[i][j] = other.mat_m[i][j];
        }
    }
}

matrix& matrix::operator=(const matrix& other)
{
    if(this != &other)
    {
        for(int i = 0; i < rows_m; i++)
        {
            delete[] mat_m[i];
        }
        delete[] mat_m;

        rows_m = other.rows_m;
        cols_m = other.cols_m;

        mat_m = new int*[rows_m];

        for(int i = 0; i < rows_m; i++)
        {
            mat_m[i] = new int[cols_m];

            for(int j = 0; j < cols_m; j++)
            {
                mat_m[i][j] = other.mat_m[i][j];
            } 
        }
    }
    return *this;
}

matrix::~matrix()
{
    for(int i = 0; i < rows_m; i ++)
    {
        delete[] mat_m[i];
    }
    delete[] mat_m;

    cols_m = 0;
    rows_m = 0;

    mat_m = nullptr;
}

std::ostream& operator<<(std::ostream& out, const matrix& matrix)
{
    for(int i = 0; i < matrix.rows_m; i++)
    {
        for(int j = 0; j < matrix.cols_m; j++)
        {
            out << matrix.mat_m[i][j] << " ";
        }
        out << std::endl;
    }

    return out;
}

void matrix::init()
{
    for(int i = 0; i < rows_m; i++)
    {
        for(int j = 0; j < cols_m; j++)
        {
            mat_m[i][j] = std::random_device{}() % 10;
        }
    }
}