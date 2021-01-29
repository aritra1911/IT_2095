/*
 * 2. Write a C++ Program for
 * class Base
 *     private:
 *     DM : x, y
 *     |
 * class Derived
 *
 * Initialise the value of x and y and display it on derived object.
 */

#include <iostream>

class Base {
    int x, y;

    public:
    Base(int a, int b) : x(a), y(b) { }

    int getX(void) { return x; }
    int getY(void) { return y; }
};

class Derived : public Base {
    public:
    Derived(int a=0, int b=0) : Base(a, b) { }

    void display(void) {
        std::cout << "x: " << getX() << std::endl
                  << "y: " << getY() << std::endl;
    }
};

int main(void) {
    int x, y;

    std::cout << "Enter value of `x`: ";
    std::cin >> x;

    std::cout << "Enter value of `y`: ";
    std::cin >> y;

    Derived obj(x, y);

    obj.display();

    return 0;
}
