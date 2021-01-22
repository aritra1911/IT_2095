/*
 * 7. Design a program using static data member to keep track of count of object created and destroyed.
 */

#include <iostream>

class Foo {
    static int constructed_count, destructed_count;
    int x;

    public:
    Foo(int x = 0) {
        constructed_count++;
        this->x = x;
    }

    static void showCount(void) {
        std::cout << "Objects created: " << constructed_count << ", " 
                  << "Objects destroyed: " << destructed_count << std::endl;
    }

    ~Foo(void) {
        destructed_count++;
    }
};

int Foo::constructed_count = 0;
int Foo::destructed_count = 0;

int main(void) {
    {
        Foo bar1;
        bar1.showCount();

        {
            Foo bar2(2);
            bar2.showCount();

            {
                Foo bar3(3);
                Foo::showCount();
            }
            bar2.showCount();
        }
        bar1.showCount();
    }
    Foo::showCount();

    return 0;
}
