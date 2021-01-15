/*
1. Display the details of all subjects' marks using an array of objects.
 */

#include <iostream>

class Subject {
    int marks;

    public:
    void read(void) {
        std::cin >> marks;
    }

    void display(void) {
        std::cout << marks << std::endl;
    }
};

int main(void) {
    int n;
    Subject* subjects;

    std::cout << "Enter no. of subjects: ";
    std::cin >> n;

    subjects = new Subject[n];

    std::cout << "\nEnter marks for each subject:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Subject #" << i + 1 << ": ";
        subjects[i].read();
    }

    std::cout << "\nMarks entered:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Subject #" << i + 1 << ": ";
        subjects[i].display();
    }

    delete[] subjects;

    return 0;
}
