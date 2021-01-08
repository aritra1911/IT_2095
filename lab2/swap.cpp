/*
 * 1. Write a program to swap two numbers using the concepts of call by value, call by address, and call by reference.
 */

#include <iostream>

void swap_by_value(int, int);
void swap_by_addr(int*, int*);
void swap_by_ref(int&, int&);

int main(void) {
    int a, b;

    std::cout << "Enter value for a: "; std::cin >> a;
    std::cout << "Enter value for b: "; std::cin >> b;

    std::cout << "Values of a & b before swapping: " << a << ", " << b << std::endl;

    swap_by_value(a, b);
    std::cout << "Values of a & b after swapping by value: " << a << ", " << b << std::endl;

    swap_by_addr(&a, &b);
    std::cout << "Values of a & b after swapping by address: " << a << ", " << b << std::endl;

    swap_by_ref(a, b);
    std::cout << "Values of a & b after swapping by reference: " << a << ", " << b << std::endl;

    return 0;
}

void swap_by_value(int a, int b) {
    int c = a;
    a = b;
    b = c;
}

void swap_by_addr(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void swap_by_ref(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}
