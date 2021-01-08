/*
 * Write a program to implement default argument in function while calculating the simple interest with parameters:
 * principal amount, rate of interest, and time. Assign default value of 8.5 to rate of interest.
 */

#include <iostream>

float calc_interest(float, float, float = 8.5);

int main(void) {
    float principal, time, rate;
    char choice;

    std::cout << "Enter principal amount: ";
    std::cin >> principal;

    std::cout << "Enter time in years: ";
    std::cin >> time;

    std::cout << "Would you like to enter rate of interest? (Y/n) ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        std::cout << "Enter rate of interest: ";
        std::cin >> rate;
        std::cout << "Interest amount = Rs." << calc_interest(principal, time, rate) << std::endl;
    } else
        std::cout << "Interest amount = Rs." << calc_interest(principal, time) << std::endl;

    return 0;
}

float calc_interest(float p, float t, float r) {
    return p * (r / 100.0f) * t;
}
