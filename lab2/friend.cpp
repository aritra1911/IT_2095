/*
 * 5. Write a program to implement friend function / friend class for:
 * (a) Pure friend function
 * (b) Friend class
 * (c) A specific member function of a class that can access the private data of another class
 */

#include <iostream>

class Bob;

class Alice {
    int x;

    public:
    void get_value() {
        std::cout << "<Alice> Enter value of x: ";
        std::cin >> x;
    }

    friend void show(Alice);
    friend class Bob;

    void showBob(Bob);
};


class Bob {
    int y;

    public:
    void get_value() {
        std::cout << "<Bob> Enter value of y: ";
        std::cin >> y;
    }

    void show(void) {
        std::cout << "<Bob> y = " << y << std::endl;
    }

    void showAlice(Alice a) {
        std::cout << "<Bob> x = " << a.x << std::endl;
    }

    friend void Alice::showBob(Bob);
};

void show(Alice);

int main(void) {
    Alice a;
    Bob b;

    // (a) Pure friend function
    a.get_value();
    show(a);

    // (b) Friend class
    b.get_value();
    b.show();
    b.showAlice(a);

    // (c) Friend a member function
    a.showBob(b);

    return 0;
}

void show(Alice a) {
    std::cout << "x = " << a.x << std::endl;
}

void Alice::showBob(Bob b) {
    std::cout << "<Alice> y = " << b.y << std::endl;
}
