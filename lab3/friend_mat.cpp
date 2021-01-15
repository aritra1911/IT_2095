/*
0. Write a program to define two classes Matrix1 & Matrix2 with data members as 2D Array and member functions as
   read() and display().
 *
 * Define a non-member function add() which will access the provate data of both Matrix1 & Matrix2 then do the matrix
   addition and finally display the result.
 */

#include <iostream>

class Matrix2;  // Forward declaration of class Matrix2

class Matrix1 {
    int m, n;
    int** matrix;

    public:
    Matrix1(int p, int q) {
        m = p;
        n = q;
        matrix = new int*[m];
        for (int i = 0; i < m; i++)
            matrix[i] = new int[n];
    }

    void read(void) {
        std::cout << "Enter data for Matrix 1:\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                std::cin >> matrix[i][j];
    }

    void display(void) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    }

    friend void add(Matrix1, Matrix2);
};

class Matrix2 {
    int m, n;
    int** matrix;

    public:
    Matrix2(int p, int q) {
        m = p;
        n = q;
        matrix = new int*[m];
        for (int i = 0; i < m; i++)
            matrix[i] = new int[n];
    }

    void read(void) {
        std::cout << "Enter data for Matrix 2:\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                std::cin >> matrix[i][j];
    }

    void display(void) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    }

    friend void add(Matrix1, Matrix2);
};

void add(Matrix1 mat1, Matrix2 mat2) {
    if (mat1.m != mat2.m || mat1.n != mat2.n) {
        std::cout << "Cannot add matrices of unequal dimensions\n";
        return;
    }

    for (int i = 0; i < mat1.m; i++) {
        for (int j = 0; j < mat1.n; j++)
            std::cout << mat1.matrix[i][j] + mat2.matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

int main(void) {
    int m, n;

    std::cout << "Enter dimensions of matrices: ";
    std::cin >> m >> n;

    std::cout << std::endl;

    Matrix1 mat1(m, n);
    Matrix2 mat2(m, n);

    mat1.read();
    std::cout << std::endl;

    mat2.read();
    std::cout << std::endl;

    std::cout << "Addtition of Matrix 1 & Matrx 2:\n";
    add(mat1, mat2);

    return 0;
}
