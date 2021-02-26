/* 
 * Q5) Create a Class TwoD with data members x_co and y_co, take the values of two co-ordinates from the user and find
 *     the distance between two points by using operator overloading.
 */

#include <iostream>
#include <cmath>

class TwoD {
    float x_co, y_co;

    public:
    void read(void) {
        std::cout << "Enter x coordinate: ";
        std::cin >> x_co;

        std::cout << "Enter y coordinate: ";
        std::cin >> y_co;
    }

    float operator - (const TwoD& c) {
        float dx = x_co - c.x_co;
        float dy = y_co - c.y_co;
        
        return sqrt(dx * dx + dy * dy);
    }
};

int main(void) {
    TwoD p1, p2;

    std::cout << "Enter coordinates for first point:\n";
    p1.read();

    std::cout << "\nEnter coordinates for first point:\n";
    p2.read();

    float distance = p2 - p1;
    std::cout << "\nDistance between two points = " << distance << " units.\n";

    return 0;
}
