/*
 * 7. Design a program using static data member to keep track of count of object created and destroyed.
 */

#include <iostream>

class Foo {
    static int count;
    int x;

    public:
    Foo(int x = 0) {
        count++;
        this->x = x;
    }

    static void showCount(void) {
        std::cout << count << std::endl;
    }

    ~Foo(void) {
        count--;
    }
};

int Foo::count = 0;

int main(void) {
    Foo bar1;

    std::cout << "Count : ";
    bar1.showCount();
    
    Foo bar2(2);
    std::cout << "Count : ";
    bar2.showCount();

    Foo bar3(3);
    std::cout << "Count : ";
    Foo::showCount();

    return 0;
}
