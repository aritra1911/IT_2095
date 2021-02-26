/*
 * Q3) WAP to demonstrate Post and pre increment operators using operator function as well as friend function.
 */

#include <iostream>

class Number {
    int n;

    public:
    Number(int num) : n(num) { }

    Number operator ++ (void) { // preincrement
        return Number(++n);
    }

    friend Number operator ++ (Number&, int);

    void display(void) {
        std::cout << n << std::endl;
    }
};

Number operator ++ (Number& num, int) {  // post increment
    return Number(num.n++);
}

int main(void) {
    int x;

    std::cout << "Enter a number: ";
    std::cin >> x;

    Number num(x);
    Number num1 = ++num;
    Number num2 = num++;

    std::cout << "num1.n = "; num1.display();
    std::cout << "num2.n = "; num2.display();
    std::cout << "num.n = "; num.display();

    return 0;
}
