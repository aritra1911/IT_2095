/*
5. Display the sum of twp complex numbers in the form of "`real` + i`imaginary`" using parameterized constructor.
 * Use proper member functions as per the requirement of the assignment.
 */

#include <iostream>

class Complex {
    float real, imag;

    public:
    Complex(float r, float im) {
        real = r;
        imag = im;
    }

    void sum(Complex& b) {
        std::cout << "Sum : " << real + b.real
                  << " + i"   << imag + b.imag
                  << std::endl;
    }
};

int main(void) {
    float real, imag;

    std::cout << "Enter first complex number:\n"
              << "Real part: ";
    std::cin >> real;
    std::cout << "Imaginary part: ";
    std::cin >> imag;

    Complex c1(real, imag);

    std::cout << "\nEnter second complex number:\n"
              << "Real part: ";
    std::cin >> real;
    std::cout << "Imaginary part: ";
    std::cin >> imag;

    Complex c2(real, imag);

    std::cout << std::endl;

    c1.sum(c2);

    return 0;
}
