#include <iostream>
#include <random>
#include "matrix.h"

matrix::matrix(int r, int c)
{
    rows = r;
    cols = c;
    matrixData = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        matrixData[i] = new int[cols];
    }
}

matrix::matrix(const matrix& other)
{
    rows = other.rows;
    cols = other.cols;
    matrixData = new int*[rows];

    for(int i = 0; i < rows; i++)
    {
        matrixData[i] = new int[cols];
        for(int j = 0; j < cols; j++)
        {
            matrixData[i][j] = other.matrixData[i][j];
        }
    }

    std::cout << "Copy constructor called" << std::endl;
}

matrix& matrix::operator=(const matrix& other)
{

        for(int i = 0; i < rows; i++)
        {
            delete[] matrixData[i];
        }
        delete[] matrixData;

        rows = other.rows;
        cols = other.cols;
        matrixData = new int*[rows];

        for(int i = 0; i < rows; i++)
        {
            matrixData[i] = new int[cols];
            for(int j = 0; j < cols; j++)
            {
                matrixData[i][j] = other.matrixData[i][j];
            }
        }

        std::cout << "Assignment operator called" << std::endl;
        return *this;
}

matrix matrix::operator*(const matrix& other)
    {
        if(cols != other.rows)
        {
            std::cout << "Cols and rows are not equal!!!" << std::endl;
            return *this;
        }
        else
        {
            matrix result(cols,other.rows);
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < other.cols; j++)
                {
                    result.matrixData[i][j] = 0;
                    for(int k = 0; k < cols; k++)
                    {
                        result.matrixData[i][j] += matrixData[i][k] * other.matrixData[k][j];
                    }
                }
            }
            return result;
        }
    }

matrix matrix::operator*(const int num)
    {
        for (int i = 0; i < rows; ++i)
            {
            for (int j = 0; j < cols; ++j)
            {
                this->matrixData[i][j] *= num;
            }
        }

        return *this;
    }

matrix matrix::operator++()
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                this->matrixData[i][j]++;
            }
        }
        return *this;
    }
    matrix matrix::operator++(int)
    {
        matrix temp= *this;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                this->matrixData[i][j]++;
            }
        }

        return temp;
    }

    void matrix::init()
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matrixData[i][j] = (i+j)%10;
            }
        }
    }

    void matrix::initRandom()
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matrixData[i][j] = std::random_device{}() % 10;
            }
        }
    }

    void matrix::print()
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                std::cout << matrixData[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void matrix::swapp()
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = i+1; j < cols; j++)
            {
                int temp = matrixData[i][j];
                matrixData[i][j] = matrixData[j][i];
                matrixData[j][i] = temp;
            }
        }
    }
    void matrix::turn()
    {
        this->swapp();
        for (int j = 0; j < cols; ++j)
        {
            for (int i = 0; i < rows / 2; ++i)
            {
                int temp = matrixData[i][j];
                matrixData[i][j] = matrixData[rows - 1 - i][j];
                matrixData[rows - 1 - i][j] = temp;
            }
        }
    }
    matrix::~matrix()
    {
        std::cout << "Destructor called" << std::endl;
        for(int i = 0; i < rows; i++)
        {
            delete[] matrixData[i];
        }
        delete[] matrixData;
    }

std::ostream& operator<<(std::ostream& out, const matrix& matrix)
{
    for(int i = 0; i < matrix.rows; i++)
    {
        for(int j = 0; j < matrix.cols; j++)
        {
            out << matrix.matrixData[i][j] << " ";
        }
        out << std::endl;
    }

    return out;
}