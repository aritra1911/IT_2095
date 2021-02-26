/*
 * Q2) Define a class PLUS having two integer member variables, use constructor to initialize the variables. Create two
 * objects of the class and overload the binary + operator to display the sum of two objects in complex number format.
 */

#include <iostream>

class Plus {
    int x, y;

    public:
    Plus(int a, int b) : x(a), y(b) { }

    Plus operator + (const Plus& ob) {
        return Plus(x + ob.x, y + ob.y);
    }

    void display(void) {
        std::cout << x << " + i" << y << std::endl;
    }
};

int main(void) {
    int x, y;

    std::cout << "Enter x1: ";
    std::cin >> x;
    std::cout << "Enter y1: ";
    std::cin >> y;

    Plus num1(x, y);

    std::cout << "\nEnter x2: ";
    std::cin >> x;
    std::cout << "Enter y2: ";
    std::cin >> y;

    Plus num2(x, y);

    Plus result = num1 + num2;

    std::cout << "\nResult: ";
    result.display();

    return 0;
}
