/*
 * 5. Define a class Mark; data members are Rolln, name marks of 5 subjects and average Avg() function to compute the
 * average obtained in five subjects.
 * Input() function to accept values for Rollno, name, marks.
 * Call the functions to display all data members of a student on the screen.
 */

#include <iostream>

const int SUBJECTS = 5;

class Mark {
    size_t rolln;
    char name[32];
    float marks[SUBJECTS];
    float average;

    public:
    void avg(void) {
        float sum = 0.0f;

        for (int i=0; i<SUBJECTS; i++)
            sum += marks[i];
        
        average = sum / SUBJECTS;
    }

    void input(void) {
        std::cout << "Enter roll no.: ";
        std::cin >> rolln;

        std::cin.ignore(10, '\n');  // eat chars including newline

        std::cout << "Enter name: ";
        std::cin.getline(name, 32, '\n');

        for (int i=0; i<SUBJECTS; i++) {
            std::cout << "Enter marks for Subject #" << (i + 1) << ": ";
            std::cin >> marks[i];
        }
    }

    void display(void) {
        std::cout << "Roll No. : " << rolln << std::endl;
        std::cout << "Name. : " << name << std::endl;
        for (int i=0; i<SUBJECTS; i++)
            std::cout << "Marks for Subject #" << (i + 1) << " : " << marks[i] << std::endl;
        std::cout << "Average marks : " << average << std::endl;
    }
};

int main(void) {
    Mark mark;

    mark.input();
    mark.avg();

    std::cout << std::endl;
    mark.display();

    return 0;
}
