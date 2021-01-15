/*
4. Initialize 2 member variables by parameterized constructor and return the values by 2 functions and display it.
 */

#include <iostream>

class Foo {
    int x, y;

    public:
    Foo(int a, int b) {
        x = a;
        y = b;
    }

    int getX(void) { return x; }
    int getY(void) { return y; }
};

int main(void) {
    int a, b;

    std::cout << "Enter 2 numbers: ";
    std::cin >> a >> b;

    Foo f(a, b);
    
    std::cout << "\nValue of a: " << f.getX();
    std::cout << "\nValue of b: " << f.getY() << std::endl;

    return 0;
}
