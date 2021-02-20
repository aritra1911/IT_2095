/*
 * Q3)
 * Class A
 *     int a
 * 
 * Class B derived from Class A
 *     int b, data member a of class A is initialized in class B
 * 
 * Class C
 *     int c
 * 
 * Class D inherited from Class B and C
 * 	Find the 2nd largest among 3 numbers by the object of class D.
 */

#include <iostream>

class A {
    protected:
    int a;
};

class B : protected A {
    protected:
    int b;

    public:
    B(int x, int y) : b(y) {
        a = x;
    }
};

class C {
    protected:
    int c;
};

class D :  private B, private C {
    int find_second_largest(void) {
        if (a > b) {
            if (a > c) {
                return (c > b) ? c : b;
            } else {
                return a;
            }
        } else {
            if (b > c) {
                return (c > a) ? c : a;
            } else {
                return b;
            }
        }
    }

    public:
    D(int x, int y, int z) : B(x, y) {
        c = z;
    }

    void show_second_largest(void) {
        std::cout << "Second largest number : " << find_second_largest() << std::endl;
    }
};

int main(void) {
    int x, y, z;

    std::cout << "Enter first number: ";
    std::cin >> x;
    std::cout << "Enter second number: ";
    std::cin >> y;
    std::cout << "Enter third number: ";
    std::cin >> z;

    D obj(x, y, z);

    obj.show_second_largest();

    return 0;
}
