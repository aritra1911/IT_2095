/*
 * 4. Write a C++ program to show how data members can be accessed through `this` pointer.
 */

#include <iostream>

class Foo {
    int x;

    public:
    Foo(int x) {
        this->x = x;
    }

    void showX(void) {
        std::cout << "X is " << this->x << std::endl;
    }
};

int main(void) {
    int x;

    std::cout << "Enter value of x: ";
    std::cin >> x;

    Foo bar(x);
    bar.showX();

    return 0;
}
