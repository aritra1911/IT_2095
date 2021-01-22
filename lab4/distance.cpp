/*
 * 6. Create two classes A and B which stores the value in distances. Class A stores distance in meters and centimeters
 * and class B in feet and inches. Write a program that can read values for the class objects and add one object of A
 * with another object of B. Use a friend function to carry out the addition operation. The object that stores the
 * results may be an object of class A or B, depending on the units in which the results are required. The display
 * should be in the format of feet and inches or meters and centimeters depending on the object on display.
 */

#include <iostream>

class B;

class A {
    int meters, cms;

    public:
    void read(void) {
        std::cout << "Enter distance in meters and centimeters: ";
        std::cin >> meters >> cms;
    }

    friend void add(const A&, const B&, A&);
    friend void add(const A&, const B&, B&);

    void show(void) {
        std::cout << "Distance is " << meters << " meters and " << cms << " centimeters\n";
    }
};

class B {
    int feet, inches;

    public:
    void read(void) {
        std::cout << "Enter distance in feet and inches: ";
        std::cin >> feet >> inches;
    }

    friend void add(const A&, const B&, A&);
    friend void add(const A&, const B&, B&);

    void show(void) {
        std::cout << "Distance is " << feet << " feet and " << inches << " inches\n";
    }
};

void add(const A& a, const B& b, A& result) {
    int inches = b.feet*12 + b.inches;
    int cms = inches * 2.54f;

    result.meters = a.meters + cms / 100;
    result.cms = a.cms + cms % 100;
}

void add(const A& a, const B& b, B& result) {
    int cms = a.meters*100 + a.cms;
    int inches = cms / 2.54f;

    result.feet = b.feet + inches / 12;
    result.inches = b.inches + inches % 12;
}

int main(void) {
    A a, result_a;
    B b, result_b;

    a.read();
    b.read();

    add(a, b, result_a);
    add(a, b, result_b);

    result_a.show();
    result_b.show();
}
