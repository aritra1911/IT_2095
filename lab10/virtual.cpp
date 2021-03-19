/* Q2) Write a C++ code to demonstrate constructor, virtual function, a pure virtual function and virtual destructor. */

#include <iostream>

class Base {
    protected:
    int x;

    public:
    Base(int x) : x(x) {
        std::cout << "Base class constructor\n";
    }

    virtual void changeX() = 0;

    virtual void showX() {
        std::cout << "X : " << x << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base class destructor\n";
    }
};

class Derived : public Base {
    public:
    Derived(int x) : Base(x) {
        std::cout << "Derived class constructor\n";
    }

    void changeX() {
        x += x / 10;
    }

    ~Derived() {
        std::cout << "Derived class destructor\n";
    }
};

int main(void) {
    Base* b = new Derived(42);
    b->changeX();
    b->showX();
    delete b;
    return 0;
}
