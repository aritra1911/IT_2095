/*
 * 1. Find the AREA of a circle using the concept of a constructor with deafault arguments.
 */

#include <iostream>

class Circle {
    float radius, area;

    public:
    Circle(float r = 1) {
        radius = r;
        area = 3.14159f * radius * radius;
    }

    void displayArea(void) {
        std::cout << "Area: " << area << std::endl;
    }
};

int main(void) {
    float radius;

    Circle c1;
    std::cout << "C1 ";
    c1.displayArea();

    std::cout << "Enter radius of circle: ";
    std::cin >> radius;

    Circle c2(radius);
    std::cout << "C2 ";
    c2.displayArea();

    return 0;
}
