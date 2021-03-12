/* Q2) Solve the above Q1 by showing the area() by base class object. */

#include <iostream>

class Polygon {
    protected:
    int height, width;

    public:
    void setData() {
        std::cout << "Enter height & width: ";
        std::cin >> height >> width;
    }

    virtual float area() {
        std::cout << "Base class Polygon called\n";
        return 0;
    }
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
    Polygon* poly;
    Rectangle rect;
    Triangle tri;

    poly = &rect;
    std::cout << "Enter data for rectangle:\n";
    poly->setData();

    poly = &tri;
    std::cout << "\nEnter data for triangle:\n";
    poly->setData();

    poly = &rect;
    std::cout << "\nArea for rectangle : " << poly->area() << " sq. units\n";

    poly = &tri;
    std::cout << "Area for triangle : " << poly->area() << " sq. units\n";

    return 0;
}
