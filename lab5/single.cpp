/* 
 * 1. Write a C++ Program to implement a single inheritance structure where the Base class has a data member `x` and the
 * Derived class has a data member `y`. The derived class initializes the values of `x` and `y` and display it inside
 * the `show()` function.
 */

#include <iostream>

class Base {
    protected:
    int x;
};

class Derived : public Base {
    int y;

    public:
    Derived(int a=0, int b=0) : y(b) {
        x = a;
    }

    void show(void) {
        std::cout << "x: " << x << std::endl
                  << "y: " << y << std::endl;
    }
};

int main(void) {
    int x, y;

    std::cout << "Enter value of `x`: ";
    std::cin >> x;

    std::cout << "Enter value of `y`: ";
    std::cin >> y;

    Derived obj(x, y);

    obj.show();

    return 0;
}
