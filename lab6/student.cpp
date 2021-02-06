/*
 * [1] Define the following classes and implement the inheritance structure to remove ambiguity in this multipath
 * inheritance.
 */

#include <iostream>
using namespace std;

class Student {
    size_t rollno;
    char branch[32];

    public:
    void read(void) {
        cout << "Roll No.: ";
        cin >> rollno;
        cin.ignore(10, '\n');
        cout << "Branch: ";
        cin.getline(branch, 32, '\n');
    }

    void display(void) {
        cout << "Roll : " << rollno <<endl
             << "Branch : " << branch << endl;
    }
};

class InternalExam : public virtual Student {
    protected:
    float sub1mark, sub2mark;

    public:
    void read(void) {
        cout << "Enter subject 1 & 2 marks of Internal Exam: ";
        cin >> sub1mark >> sub2mark;
    }

    void display(void) {
        cout << "Subject 1: " << sub1mark << endl
             << "Subject 2: " << sub2mark << endl;
    }
};

class ExternalExam : public virtual Student {
    protected:
    float sub1mark, sub2mark;

    public:
    void read(void) {
        cout << "Enter subject 1 & 2 marks of External Exam: ";
        cin >> sub1mark >> sub2mark;
    }

    void display(void) {
        cout << "sub1: " << sub1mark << endl
             << "sub2: " << sub2mark << endl;
    }
};

class Result : public InternalExam, public ExternalExam {
    float total;

    public:
    void total_mark(void) {
        total = InternalExam::sub1mark + ExternalExam::sub1mark +
                InternalExam::sub2mark + ExternalExam::sub2mark;
    }

    void display(void) {
        Student::display();
        cout << "Total : " << total << endl;
    }
};

int main(void) {
    Result res;
    res.Student::read();
    res.InternalExam::read();
    res.ExternalExam::read();
    res.total_mark();
    res.display();
    return 0;
}
