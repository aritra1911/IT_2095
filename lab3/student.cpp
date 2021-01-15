/*
3. Display your student details by a default constructor.
 */

#include <iostream>

class Student {
    public:
    Student(void) {
        std::cout << "   Name  : Aritra Sarkar\n";
        std::cout << "Roll No. : 1930012\n";
        std::cout << " Branch  : Electronics & Computer Science Engineering\n";
    }
};

int main(void) {
    Student s;

    return 0;
}
