#include <iostream>

class Vehicle {
    protected:
    char name[32];
    int wheels;

    public:
    void read(void) {
        std::cout << "Enter name of vehicle: ";
        std::cin.getline(name, 32, '\n');
        std::cout << "Enter no. of wheels: ";
        std::cin >> wheels;
    }

    void display(void) {
        std::cout << "Name : " << name << std::endl
                  << "Wheels : " << wheels << std::endl;
    }
};

class LightGear : public Vehicle {
    protected:
    float speed_limit;

    public:
    void read(void) {
        Vehicle::read();
        std::cout << "Enter speed limit of vehicle: ";
        std::cin >> speed_limit;
    }

    void display(void) {
        Vehicle::display();
        std::cout << "Speed Limit : " << speed_limit << std::endl;
    }
};

class HeavyGear : public Vehicle {
    protected:
    int load_capacity, permit;

    public:
    void read(void) {
        Vehicle::read();
        std::cout << "Enter load capacity: ";
        std::cin >> load_capacity;
        std::cout << "Enter permit: ";
        std::cin >> permit;
    }

    void display(void) {
        Vehicle::display();
        std::cout << "Load Capacity : " << load_capacity << std::endl
                  << "Permit : " << permit << std::endl;
    }
};

class GearMotor : public LightGear {
    protected:
    int gear_count;

    public:
    void read(void) {
        LightGear::read();
        std::cout << "Enter gear count: ";
        std::cin >> gear_count;
    }

    void display(void) {
        LightGear::display();
        std::cout << "Gear Count : " << gear_count << std::endl;
    }
};

class NonGearMotor : public LightGear {
    public:
    void read(void) {
        LightGear::read();
    }

    void display(void) {
        LightGear::display();
    }
};

class Passenger : public HeavyGear {
    protected:
    int sitting_capacity, standing_capacity;

    public:
    void read(void) {
        HeavyGear::read();
        std::cout << "Enter sitting capacity: ";
        std::cin >> sitting_capacity;
        std::cout << "Enter standing capacity: ";
        std::cin >> standing_capacity;
    }

    void display(void) {
        HeavyGear::display();
        std::cout << "Sitting Capacity : " << sitting_capacity << std::endl
                  << "Standing Capacity : " << standing_capacity << std::endl;
    }
};

class Goods : public HeavyGear {
    protected:
    char type[32];

    public:
    void read(void) {
        HeavyGear::read();
        std::cin.ignore(10, '\n');  // eat chars, including newline
        std::cout << "Enter type of goods: ";
        std::cin.getline(type, 32, '\n');
    }

    void display(void) {
        HeavyGear::display();
        std::cout << "Type : " << type << std::endl;
    }
};

int main(void) {
    GearMotor gm;
    NonGearMotor ngm;
    Passenger passenger;
    Goods goods;

    gm.read();
    gm.display();

    std::cout << std::endl;

    std::cin.ignore(10, '\n');  // eat chars, including newline
    ngm.read();
    ngm.display();

    std::cout << std::endl;

    std::cin.ignore(10, '\n');  // eat chars, including newline
    passenger.read();
    passenger.display();

    std::cout << std::endl;

    std::cin.ignore(10, '\n');  // eat chars, including newline
    goods.read();
    goods.display();

    return 0;
}
