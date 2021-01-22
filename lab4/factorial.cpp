/*
 * 8. Find the factorial of a number using copy constructor.
 */

#include <iostream>

class Factorial {
    size_t n;
    size_t factorial;

    public:
    Factorial(size_t n = 0) {
        this->n = n;
    }

    Factorial(const Factorial &fact2) {
        n = fact2.n;
        factorial = fact(n);
    }
    
    size_t fact(size_t n) {
        return n == 0 ? 1 : n * fact(n-1);
    }

    void showFactorial(void) {
        std::cout << "Factorial of " << n << " is " << factorial << ".\n" ;
    }
};

int main(void) {
    size_t n;

    std::cout << "Enter number: ";
    std::cin >> n;

    Factorial f1(n);
    Factorial f2 = f1;

    f2.showFactorial();

    return 0;
}
