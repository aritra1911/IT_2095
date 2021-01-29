/*
 * 3.
 * A DM : x, y, z
 *  |
 * B DM : a, b, c
 *  |
 * C DM : i, j, k
 *
 * Initialize the data members and display it by object of C, display the order of constructors and destructors.
 */

#include <iostream>

class A {
    protected:
    int x, y, z;

    public:
    A(void) {
        x = 1; y = 2; z = 3;
        std::cout << "A's constructor called\n";
    }

    ~A(void) {
        std::cout << "A's destructor called\n";
    }
};

class B : public A {
    protected:
    int a, b, c;

    public:
    B(void) {
        a = 4; b = 5; c = 6;
        std::cout << "B's constructor called\n";
    }

    ~B(void) {
        std::cout << "B's destructor called\n";
    }
};

class C : public B {
    protected:
    int i, j, k;

    public:
    C(void) {
        i = 4; j = 5; k = 6;
        std::cout << "C's constructor called\n";
    }

    ~C(void) {
        std::cout << "C's destructor called\n";
    }

    void display(void) {
        std::cout << "x: " << x << std::endl
                  << "y: " << y << std::endl
                  << "z: " << z << std::endl
                  << "a: " << a << std::endl
                  << "b: " << b << std::endl
                  << "c: " << c << std::endl
                  << "i: " << i << std::endl
                  << "j: " << j << std::endl
                  << "k: " << k << std::endl;
    }
};

int main(void) {
    C obj;

    obj.display();

    return 0;
}
