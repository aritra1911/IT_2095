/* Q1)
 * Class Base
 *   int num1
 * Class D1 derived from Base
 *   int num2
 * Class D2 derived from D1
 *   int num3
 * Class Largest derived from D2
 *
 * Display the largest among 3 numbers using the object of Largest class.
 */

#include <iostream>

class Base {
    protected:
    int num1;
};

class D1 : protected Base {
    protected:
    int num2;
};

class D2 : protected D1 {
    protected:
    int num3;
};

class Largest : private D2 {
    public:
    Largest(int a, int b, int c) {
        num1 = a;
        num2 = b;
        num3 = c;
    }

    void show_largest(void) {
        std::cout << "Largest number : " << ((num1 > num2) ? ((num1 > num3) ? num1 : num3)
                                                           : ((num2 > num3) ? num2 : num3))
                                         << std::endl;
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

    Largest obj(x, y, z);

    obj.show_largest();

    return 0;
}
