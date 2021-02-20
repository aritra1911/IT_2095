/*
 * Q4)Class A
 *    int num1 and returnFactorial()
 * 
 * Class B derived from A
 *    int num2
 * 
 * Class C derived from A
 *    int num3
 * 
 * Class D derived from B and C
 *    returnLargest()
 * 
 * find the factorial of num1 and find the largest among 3 numbers and display both using object of class D
 */

#include <iostream>

class A {
    int fact(int n) {
        return (n == 0) ? 1 : n * fact(n - 1);
    }

    protected:
    int num1;

    int returnFactorial(void) {
        return fact(num1);
    }
};

class B : virtual protected A {
    protected:
    int num2;
};

class C : virtual protected A {
    protected:
    int num3;
};

class D : protected B, protected C {
    int returnLargest() {
        return ((num1 > num2) ? ((num1 > num3) ? num1 : num3)
                              : ((num2 > num3) ? num2 : num3));
    }

    public:
    D(int a, int b, int c) {
        num1 = a;
        num2 = b;
        num3 = c;
    }

    void show(void) {
        std::cout << "Factorial of num1 : " << returnFactorial() << std::endl
                  << "Largest number : "    << returnLargest()   << std::endl;
    }
};

int main(void) {
    int x, y, z;

    std::cout << "Enter num1: ";
    std::cin >> x;
    std::cout << "Enter num2: ";
    std::cin >> y;
    std::cout << "Enter num3: ";
    std::cin >> z;

    D obj(x, y, z);

    std::cout << std::endl;
    obj.show();

    return 0;
}
