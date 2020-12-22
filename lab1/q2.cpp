/*
 * Create a structure named `Student` with the variables as above (Name, Roll, Branch, Section), input the details from
 * keyboard and display it.
 */
#include <iostream>

typedef struct {
    size_t roll;
    std::string name, branch, section;
} Student;

int main(void) {
    Student s;

    std::cout << "Enter your Name: ";
    getline(std::cin, s.name);

    std::cout << "Enter your Roll No.: ";
    std::cin >> s.roll;

    std::cin.ignore(10, '\n');  // eat chars, including newline

    std::cout << "Enter your Branch: ";
    getline(std::cin, s.branch);

    std::cout << "Enter your Section: ";
    getline(std::cin, s.section);

    std::cout <<                               std::endl
              << "    Name : " << s.name    << std::endl
              << "Roll No. : " << s.roll    << std::endl
              << "  Branch : " << s.branch  << std::endl
              << " Section : " << s.section << std::endl;

    return 0;
}
