/*
 * 2. Write a C++ program to calculate the area of triangle, rectangle and circle using constructor overloading.
 */

#include <iostream>

class Area {
    float area;

    public:
    Area(int l, int b) {  // Overload for Area Of Rectangle
        area = l * b;
    }

    Area(float b, float h) {  // Overload for Area Of Triangle
        area = 0.5f * b * h;
    }

    Area(float r) {  // Overload for Area of Circle
        area = 3.14159f * r * r;
    }

    void displayArea(void) {
        std::cout << "Area: " << area << std::endl;
    }
};

int main(void) {
    int length, breadth;
    float base, height, radius;

    std::cout << "Enter length & breadth for area of rectangle: ";
    std::cin >> length >> breadth;
    Area rectangle(length, breadth);

    std::cout << "Enter base & height for area of triangle: ";
    std::cin >> base >> height;
    Area triangle(base, height);

    std::cout << "Enter radius for area of circle: ";
    std::cin >> radius;
    Area circle(radius);

    std::cout << "Rectangle ";
    rectangle.displayArea();

    std::cout << "Triangle ";
    triangle.displayArea();

    std::cout << "Circle";
    circle.displayArea();

    return 0;
}
