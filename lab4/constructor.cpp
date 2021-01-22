/*
 * 3. Write all possible ways to initialize the data members by constructors.
 */

#include <iostream>

class Foo {
    int x;

    public:
    Foo(void) : x(0) { }
    Foo(int y) : x(y) { }

    void show(void) {
        std::cout << "X is " << x << std::endl;
    }
};

int main(void) {
    int x;

    Foo bar;
    bar.show();

    std::cout << "Enter value of X: ";
    std::cin >> x;

    Foo bar1(x);
    bar1.show();

    return 0;
}
