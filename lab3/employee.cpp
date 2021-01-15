/*
2. Create a class to store the following information about an employee:
   Name, Emp. Id, Salary.
 * Store the information of 10 employees. Calculate gross salary. Display all the information of all the
   employees in tabular form. Display the size of the class.
 */

#include <iostream>

const size_t EMPLOYEES = 10;
const float GROSS_FACTOR = 1.01f;

class Employee {
    size_t empId;
    std::string name;
    float salary, gross;

    public:
    void read(void) {
        std::cout << "Enter Employee Id: ";
        std::cin >> empId;

        std::cin.ignore(10, '\n');  // eat chars, including newline

        std::cout << "Enter name: ";
        getline(std::cin, name);

        std::cout << "Enter salary: ";
        std::cin >> salary;
    }

    void calcGross(void) {
        gross = GROSS_FACTOR * salary;
    }

    void displayRow(void) {
        std::cout << empId  << '\t'
                  << name   << '\t'
                  << salary << '\t'
                  << gross
                  << std::endl;
    }
};

int main(void) {
    Employee employees[EMPLOYEES];

    // Input all employees
    for (size_t i=0; i<EMPLOYEES; i++) {
        employees[i].read();
        std::cout << std::endl;
    }
    
    // Calculate their gross salaries
    for (size_t i=0; i<EMPLOYEES; i++)
        employees[i].calcGross();

    // Print table header
    std::cout << "Emp. Id\tName\tSalary\tGross Salary\n";

    // Display all employees
    for (size_t i=0; i<EMPLOYEES; i++)
        employees[i].displayRow();

    // Display size of class Employee
    std::cout << "\nSize of class Employee : " << sizeof(Employee) << " bytes\n";

    return 0;
}
