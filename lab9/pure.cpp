/* Q4) Write a simple code to demonstrate use of pure virtual function and abstract base class. */

#include <iostream>

class Alpha {
    protected:
    int x;

    public:
    Alpha(int a) : x(a) { }

    virtual void func() = 0;
};

class Beta : public Alpha {
    public:
    Beta(int a=42) : Alpha(a) { }

    void func() {
        std::cout << x + 10 << std::endl;
    }
};

int main(void) {
    //Alpha a(35);  // Error: Cannot instantiate an Abstract class

    Beta b(54);
    b.func();

    Alpha* a = &b;
    a->func();

    return 0;
}
