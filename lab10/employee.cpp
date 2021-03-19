/* Q1) Create a class which stores employee name,id and salary Derive two classes from Employee class: `Regular' and
 * `Part-Time'. The `Regular' class stores DA, HRA and basic salary. The `Part-Time' class stores the number of hours
 * and pay per hour. Calculate the salary of a regular employee and a part-time employee, using virtual function.
 */

#include <iostream>

class Employee {
    char name[32];
    unsigned long id;

    protected:
    float salary;

    public:
    void get_data() {
        std::cout << "Enter name of employee: ";
        std::cin.getline(name, 32, '\n');
        std::cout << "Enter employee id: ";
        std::cin >> id;
        std::cout << "Enter salary: ";
        std::cin >> salary;
    }

    virtual float calcSalary() = 0;

    void show_data() {
        std::cout.width(16);
        std::cout << "Name : ";
        std::cout.width(32);
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout << name << std::endl;
        std::cout.width(16);
        std::cout.setf(std::ios::right, std::ios::adjustfield);
        std::cout << "ID : ";
        std::cout.width(32);
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout << id << std::endl;
        std::cout.width(16);
        std::cout.setf(std::ios::right, std::ios::adjustfield);
        std::cout << "Salary : ";
        std::cout.width(32);
        std::cout.setf(std::ios::showpoint);
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout << salary << std::endl;
        std::cout.width(16);
        std::cout.setf(std::ios::right, std::ios::adjustfield);
        std::cout << "Total Salary : ";
        std::cout.width(32);
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout << calcSalary() << std::endl;
    }
};

class Regular : public Employee {
    float da, hra, basic_sal;

    public:
    void get_data() {
        Employee::get_data();
        std::cout << "Enter DA: ";
        std::cin >> da;
        std::cout << "Enter HRA: ";
        std::cin >> hra;
        std::cout << "Enter basic salary: ";
        std::cin >> basic_sal;
    }

    float calcSalary() {
        return salary + da + hra + basic_sal;
    }
};

class PartTime : public Employee {
    int hours;
    float pay_per_hour;

    public:
    float calcSalary() {
        return salary + pay_per_hour * hours;
    }
};

int main(void) {
    Regular r;
    r.get_data();
    r.show_data();
    return 0;
}
