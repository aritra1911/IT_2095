/*
 * Do the Q2 using a pointer of the structure variable.
 */
#include <iostream>

typedef struct {
    size_t roll;
    std::string name, branch, section;
} Student;

int main(void) {
    Student* sptr = new Student;

    std::cout << "Enter your Name: ";
    getline(std::cin, sptr->name);

    std::cout << "Enter your Roll No.: ";
    std::cin >> sptr->roll;

    std::cin.ignore(10, '\n');  // eat chars, including newline

    std::cout << "Enter your Branch: ";
    getline(std::cin, sptr->branch);

    std::cout << "Enter your Section: ";
    getline(std::cin, sptr->section);

    std::cout <<                                   std::endl
              << "    Name : " << sptr->name    << std::endl
              << "Roll No. : " << sptr->roll    << std::endl
              << "  Branch : " << sptr->branch  << std::endl
              << " Section : " << sptr->section << std::endl;

    delete sptr;

    return 0;
}
