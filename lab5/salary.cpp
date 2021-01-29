/*
 * 5.
 * Class employee
 * DM:empid, empname
 *        I
 * Class Salary
 * DM : basic, DA, HRA, EPF
 * MF: Gross ();
 * Gross= ((basic+da+hra)-epf))
 * 
 * Details()
 * 
 * Input the details, calculate and display all details of an employee
 */

#include <iostream>

class Employee {
    protected:
    char empid[8], empname[32];

    public:
    Employee(void) {
        std::cout << "Enter employee id: ";
        std::cin.getline(empid, 8, '\n');
        std::cout << "Enter employee name: ";
        std::cin.getline(empname, 32, '\n');
    }
};

class Salary : public Employee {
    float basic, da, hra, epf, grs;

    public:
    Salary(void) {
        std::cout << "Enter basic pay: ";
        std::cin >> basic;
        std::cout << "Enter DA: ";
        std::cin >> da;
        std::cout << "Enter HRA: ";
        std::cin >> hra;
        std::cout << "Enter EPF: ";
        std::cin >> epf;
    }

    void gross(void) {
        grs = ((basic + da + hra) - epf);
    }

    void details(void) {
        std::cout << "  Employee id : " << empid << std::endl
                  << "Employee name : " << empname << std::endl
                  << "    Basic pay : " << basic << std::endl
                  << "           DA : " << da << std::endl
                  << "          HRA : " << hra << std::endl
                  << "          EPF : " << epf << std::endl
                  << " Gross salary : " << grs << std::endl;
    }
};

int main(void) {
    Salary s;

    s.gross();

    std::cout << std::endl;
    s.details();

    return 0;
}
