/*
 * Write a program to implement inline functions.
 */

#include <iostream>

void inline get_values(void);
void inline show_value(void);

int a, b, c;

int main(void) {
    get_values();

    c = a + b;

    show_value();
}

void inline get_values(void) {
    std::cout << "Enter value for a: ";
    std::cin >> a;

    std::cout << "Enter value for b: ";
    std::cin >> b;
}

void inline show_value(void) {
    std::cout << "Value of c : " << c << std::endl;
}
