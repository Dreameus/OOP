#include <iostream>
#include <random>

class matrix{
private:
    int rows;
    int cols;
    int** matrixData;

    public:

    matrix(int r, int c)
    {
        rows = r;
        cols = c;
        matrixData = new int*[rows];
        for(int i = 0; i < rows; i++)
        {
            matrixData[i] = new int[cols];
        }
    }
    
    matrix(const matrix& other)
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

    matrix& operator=(const matrix& other)
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
        std::cout << "Assignment operator called" << std::endl;
        return *this;
    }

    void init()
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matrixData[i][j] = (i+j)%10;
            }
        }
    }

    void initRandom()
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matrixData[i][j] = std::random_device{}() % 10;
            }
        }
    }

    void print()
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

    void swapp()
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
    void turn()
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
    ~matrix()
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] matrixData[i];
        }
        delete[] matrixData;
    }
};

int main()
{
    matrix mat(10, 10);
    mat.init();
    std::cout << "Original Matrix:" << std::endl;
    mat.print();
    mat.swapp();
    std::cout << "Transposed Matrix:" << std::endl;
    mat.print();
    std::cout << "Turn matrix" << std::endl;
    mat.turn();
    mat.print();

    matrix mat2 = mat;
    std::cout << "Copied Matrix:" << std::endl;
    matrix mat3(4, 4);
    mat3 = mat;

    return 0;
}