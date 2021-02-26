/*
 * Q6) Write a program to demonstrate the insertion and extraction operator overloading.
 */

#include <iostream>

class Point {
    int x, y;

    public:
    friend std::istream& operator >> (std::istream&, Point&);
    friend std::ostream& operator << (std::ostream&, Point&);
};

std::istream& operator >> (std::istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

std::ostream& operator << (std::ostream& out, Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main(void) {
    Point p;

    std::cout << "Enter x and y coordinates: ";
    std::cin >> p;

    std::cout << "Point is : " << p << std::endl;

    return 0;
}
