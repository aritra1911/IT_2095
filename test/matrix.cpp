#include <iostream>

class Matrix_012 {
    public:
    int** twodarray_012;
    int row_size_012, col_size_012;

    Matrix_012(int rows_012, int cols_012) : row_size_012(rows_012), col_size_012(cols_012) {
        twodarray_012 = new int*[row_size_012];

        for (int i=0; i<rows_012; i++) {
            twodarray_012[i] = new int[col_size_012];
        }
    }

    virtual void add(const Matrix_012&, const Matrix_012&) = 0;

    void display() {
        for (int i=0; i<row_size_012; i++) {
            for (int j=0; j<col_size_012; j++) {
                std::cout << twodarray_012[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    void input() {
        for (int i=0; i<row_size_012; i++) {
            for (int j=0; j<col_size_012; j++) {
                std::cin >> twodarray_012[i][j];
            }
        }
    }
};

class Addition : public Matrix_012 {
    public:
    Addition(int rows, int cols) : Matrix_012(rows, cols) { }
    
    void add(const Matrix_012& a, const Matrix_012& b) {
        if (a.row_size_012 != b.row_size_012 || a.col_size_012 != b.col_size_012)
            throw Addition(0, 0);

        for (int i=0; i<a.row_size_012; i++) {
            for (int j=0; j<b.col_size_012; j++) {
                twodarray_012[i][j] = a.twodarray_012[i][j] + b.twodarray_012[i][j];
            }
        }
    }
};

int main(void) {
    std::cout << "Name : Aritra Sarkar\nRoll No. : 1930012\n\n";

    int rows, cols;
    std::cout << "Enter # of rows: ";
    std::cin >> rows;
    std::cout << "Enter # of columns: ";
    std::cin >> cols;

    Addition a(rows, cols), b(rows, cols), res(rows, cols);
    std::cout << "\nEnter matrix A:\n";
    a.input();
    std::cout << "\nEnter matrix B:\n";
    b.input();

    try {
        res.add(a, b);
    } catch(Addition) {
        std::cerr << "Cannot add! matrix addition rule not satisfied!\n";
        return 1;
    }

    std::cout << "\nResult is:\n";
    res.display();

    return 0;
}
