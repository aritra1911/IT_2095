/*
 * Writea a program to implement function overloading while calculating area of a triangle, circle and rectangle.
 */

#include <iostream>

#define PI 3.1415926535897932384626

float area(float, float);
float area(float);
int area(int, int);

int main(void) {
    float base, height, radius;
    int length, breadth;

    std::cout << "Enter base and height of triangle: ";
    std::cin >> base >> height;
    std::cout << "Area of triangle : " << area(base, height) << std::endl;

    std::cout << std::endl;

    std::cout << "Enter radius of circle: ";
    std::cin >> radius;
    std::cout << "Area of circle : " << area(radius) << std::endl;

    std::cout << std::endl;

    std::cout << "Enter length and breadth of rectangle: ";
    std::cin >> length >> breadth;
    std::cout << "Area of rectangle : " << area(length, breadth) << std::endl;

    return 0;
}

float area(float b, float h) {  // triangle
    return 0.5f * b * h;
}

float area(float r) {  // triangle
    return PI * r * r;
}

int area(int l, int b) {  // triangle
    return l * b;
}
