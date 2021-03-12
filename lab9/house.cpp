/* Q5) Create a class called House. OneBHK and TwoBHK are two classes inherited from House with data members of data
 * members length height and width of evry room. . Area (), Volume() are functions to find area of individual room
 * .Total_area() and Total_Volume() are functions to calculate area of  total area and total volume of the houses .Write
 * the code using pure virtual function. */

#include <iostream>

struct Room {
    float length, height, width;
};

class House {
    protected:
    Room* rooms;
    int num_rooms;

    public:
    House(int n) : num_rooms(n) {
        rooms = new Room[num_rooms];
    }

    void getRoomDimensions() {
        for (int i=0; i<num_rooms; i++) {
            std::cout << "ROOM #" << i+1
                      << "\n-------\n";
            std::cout << "Enter length: ";
            std::cin  >> rooms[0].length;
            std::cout << "Enter  width: ";
            std::cin  >> rooms[0].width;
            std::cout << "Enter height: ";
            std::cin  >> rooms[0].height;
            std::cout << std::endl;
        }
    }

    virtual float area(const Room&) = 0;

    float volume(const Room& r) {
        return area(r) * r.height;
    }

    float totalArea() {
        float retval = 0.0f;

        for (int i=0; i<num_rooms; i++)
            retval += area(rooms[i]);

        return retval;
    }

    float totalVolume() {
        float retval = 0.0f;

        for (int i=0; i<num_rooms; i++)
            retval += volume(rooms[i]);

        return retval;
    }

    ~House() {
        delete[] rooms;
    }
};

class OneBHK : public House {
    public:
    OneBHK() : House(3) { }

    float area(const Room& r) {
        return r.length * r.width;
    }
};

class TwoBHK : public House {
    public:
    TwoBHK() : House(4) { }

    float area(const Room& r) {
        return 2.0f * r.length * r.width;
    }
};

int main(void) {
    OneBHK one;
    TwoBHK two;

    std::cout << "ONE BHK\n";
    one.getRoomDimensions();
    std::cout << "  Total Area : " << one.totalArea()   << " sq. units\n"
              << "Total Volume : " << one.totalVolume() << " sq. units\n";
    
    std::cout << std::endl;

    std::cout << "TWO BHK\n";
    two.getRoomDimensions();
    std::cout << "  Total Area : " << two.totalArea()   << " sq. units\n"
              << "Total Volume : " << two.totalVolume() << " sq. units\n";

    return 0;
}
