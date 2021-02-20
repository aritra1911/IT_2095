/*
 * Q5)
 * Class Student
 *       roll,name,sub
 *
 * Class Mark derived from Student
 *       labRec,Quiz,Viva
 *
 * Class Cont_Eva
 * 	C1,C2
 *
 * Class Result derived from Mark and Cont_Eva
 * 	Input marks are out of 20, display the total marks and CGPA from Result class object.
 */

#include <iostream>

class Student {
    protected:
    unsigned int roll;
    char name[32], sub[64];
};

class Mark : protected Student {
    protected:
    float labRec, quiz, viva;
};

class Cont_Eva {
    protected:
    int C1, C2;
};

class Result : private Mark, private Cont_Eva {
    public:
    void read(void) {
        std::cout << "Enter student's roll no.: ";
        std::cin >> roll;

        std::cin.ignore(10, '\n');

        std::cout << "Enter student's name: ";
        std::cin.getline(name, 32, '\n');

        std::cout << "Enter subject: ";
        std::cin.getline(sub, 64, '\n');

        std::cout << "Enter marks for lab record: ";
        std::cin >> labRec;

        std::cout << "Enter marks for quiz: ";
        std::cin >> quiz;

        std::cout << "Enter marks for viva: ";
        std::cin >> viva;

        std::cout << "Enter continuous evaluation value for C1: ";
        std::cin >> C1;

        std::cout << "Enter continuous evaluation value for C2: ";
        std::cin >> C2;
    }

    void display(void) {
        float total_marks = labRec + quiz + viva + C1 + C2;
        std::cout << "Roll No. : " << roll << std::endl
                  << "Name : " << name << std::endl
                  << "Subject : " << sub << std::endl
                  << "Total Marks : " << total_marks << std::endl
                  << "CGPA : " << (total_marks * 10.0f / (5.0f * 20.0f)) << std::endl;
    }
};

int main(void) {
    Result res;

    res.read();
    std::cout << std::endl;
    res.display();

    return 0;
}
