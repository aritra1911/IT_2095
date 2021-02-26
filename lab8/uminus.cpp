/*
 * Q1) Write a C++ program which will demonstrate overloading of unary minus operator.
 */

#include <iostream>

class Number {
    int n;

    public:
    Number(int n) {
        this->n = n;
    }

    Number operator - (void) {
        return Number(-n);
    }

    void display(void) {
        std::cout << n << std::endl;
    }
};

int main(void) {
    int x;

    std::cout << "Enter a number: ";
    std::cin >> x;

    Number num(x);
    Number n_num = -num;
    n_num.display();

    return 0;
}
