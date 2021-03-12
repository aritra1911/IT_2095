/* Q1) Create a class Yourroll_Polygon with data member roll_height and roll_width and a member function roll_setData().
 * Rectangle and Triangle are two classes and both having derived from Yourroll_Polygon. Set values for both derived
 * classes and display the area() by derived class object.
 */

#include <iostream>

class Polygon {
    protected:
    int height, width;

    public:
    void setData() {
        std::cout << "Enter height & width: ";
        std::cin >> height >> width;
    }

    //virtual float area() = 0;
};

class Rectangle : public Polygon {
    public:
    float area() {
        return height * width;
    }
};

class Triangle: public Polygon {
    public:
    float area() {
        return 0.5 * height * width;
    }
};

int main(void) {
    Rectangle rect;
    Triangle tri;

    std::cout << "Enter data for rectangle:\n";
    rect.setData();

    std::cout << "\nEnter data for triangle:\n";
    tri.setData();

    std::cout << "\nArea for rectangle : " << rect.area() << " sq. units\n";
    std::cout << "Area for triangle : " << tri.area() << " sq. units\n";

    return 0;
}
