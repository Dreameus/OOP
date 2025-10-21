#include <iostream>
#include <random>

class matrix{
private:
    int rows;
    int cols;
    int** matrixData;

    public:

    matrix(int r, int c){
        rows = r;
        cols = c;
        matrixData = new int*[rows];
        for(int i = 0; i < rows; i++)
        {
            matrixData[i] = new int[cols];
        }
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

    void turnMatrix()
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
    matrix mat(4, 4);
    mat.initRandom();
    std::cout << "Original Matrix:" << std::endl;
    mat.print();
    mat.turnMatrix();
    std::cout << "Transposed Matrix:" << std::endl;
    mat.print();
    

    return 0;
}