/* Q3) Create an abstract class Student. IT , CSE , and CSCE are 3 classes derived from Student, Input the student
 * Details ( roll , name, branch, section) and display the details using base class array of pointers.
 * Note: All display functions should display the data using manipulators.
 */

#include <iostream>
#include <iomanip>

class Student {
    protected:
    unsigned int roll;
    char name[32];
    char section[6];

    public:
    void get_data() {
        std::cout << "Enter roll: ";
        std::cin >> roll;
        std::cout << "Enter name: ";
        std::cin.ignore(10, '\n');
        std::cin.getline(name, 32, '\n');
        std::cout << "Enter section: ";
        std::cin.getline(section, 6, '\n');
    }

    static void display_header() {
        std::cout << std::setw(8) << std::right << "ROLL"
                  << " "
                  << std::setw(32) << std::left << "NAME"
                  << std::setw(16) << std::left << "BRANCH"
                  << "SECTION" << std::endl;
    }

    virtual void display_row() = 0;
};

class IT : public Student {
    void display_row() {
        std::cout << std::setw(8) << std::right << roll
                  << " "
                  << std::setw(32) << std::left << name
                  << std::setw(16) << std::left << "IT"
                  << section << std::endl;

    }
};

class CSE : public Student {
    void display_row() {
        std::cout << std::setw(8) << std::right << roll
                  << " "
                  << std::setw(32) << std::left << name
                  << std::setw(16) << std::left << "CSE"
                  << section << std::endl;

    }
};

class CSCE : public Student {
    void display_row() {
        std::cout << std::setw(8) << std::right << roll
                  << " "
                  << std::setw(32) << std::left << name
                  << std::setw(16) << std::left << "CSCE"
                  << section << std::endl;

    }
};

int main(void) {
    Student* ptr[3];
    ptr[0] = new IT();
    ptr[1] = new CSE();
    ptr[2] = new CSCE();

    for (int i=0; i<3; i++)
        ptr[i]->get_data();

    Student::display_header();

    for (int i=0; i<3; i++)
        ptr[i]->display_row();

    return 0;
}
