#ifndef MATRIX_H
#define MATRIX_H

class matrix{
private:
    int rows;
    int cols;
    int** matrixData;

public:
    matrix(int r, int c);
    matrix(const matrix& other);
    matrix& operator=(const matrix& other);
    matrix operator*(const matrix& other);
    matrix operator*(const int num);
    matrix operator++();
    matrix operator++(int);
    friend std::ostream& operator<<(std::ostream& out, const matrix& matrix);
    void init();
    void initRandom();
    void print();
    void swapp();
    void turn();
    ~matrix();
    matrix(matrix&& other);
    matrix& operator=(matrix&& other);
};

#endif