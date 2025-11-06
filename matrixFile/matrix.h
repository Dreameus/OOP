#ifndef MATRIX_H
#define MATRIX_H

class matrix{
private:
    int rows_m;
    int cols_m;
    int** mat_m = nullptr;
public:
    matrix(int rows, int cols);
    matrix(const matrix& other);
    matrix& operator=(const matrix& other);
    ~matrix();
public:
    friend std::ostream& operator<<(std::ostream& out, const matrix& matrix);
public:
    void init();
};

#endif //MATRIX_H