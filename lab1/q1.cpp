/*
 * Write a C++ Program to input your details like Name, Roll, Branch, Section from Keyboard and display it.
 */
#include <iostream>

int main(void) {
    size_t roll;
    std::string name, branch, section;

    std::cout << "Enter your Name: ";
    getline(std::cin, name);

    std::cout << "Enter your Roll No.: ";
    std::cin >> roll;

    std::cin.ignore(10, '\n');  // eat chars, including newline

    std::cout << "Enter your Branch: ";
    getline(std::cin, branch);

    std::cout << "Enter your Section: ";
    getline(std::cin, section);

    std::cout <<                             std::endl
              << "    Name : " << name    << std::endl
              << "Roll No. : " << roll    << std::endl
              << "  Branch : " << branch  << std::endl
              << " Section : " << section << std::endl;

    return 0;
}
