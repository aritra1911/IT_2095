/* Q5) Illustrate the use of an Abstract class. */

#include <iostream>

class Base {
    public:
    virtual void func() = 0;
};

class Derived : public Base {
    public:
    void func() {
        std::cout << "Inside func() of class Derived\n";
    }
};

int main(void) {
    //Base b;  // Error: Cannot instantiate an abstract class
    //b.func();  // Error: Pure virtual functions have no definition

    Derived d;
    d.func();

    return 0;
}
