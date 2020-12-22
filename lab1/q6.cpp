/*
 * Use the structure of Q3 for 10 employees and display the details of the employees in the order in 3 slabs.
 *      Slab 1 : salary <= 10,000
 *      Slab 2 : salary > 50,000
 *      Slab 3 : 10,000 < salary < 50,000
 */
#include <iostream>

const size_t EMPLOYEES = 10;

typedef struct {
    size_t empNo;
    std::string name, dept;
    double salary;
} Employee;

void displayEmployee(Employee);

int main(void) {
    Employee employees[EMPLOYEES];

    // Input all employees
    for (size_t i=0; i<EMPLOYEES; i++) {
        std::cout << "Enter employee no.: ";
        std::cin >> employees[i].empNo;

        std::cin.ignore(10, '\n');  // eat chars, including newline

        std::cout << "Enter name: ";
        getline(std::cin, employees[i].name);

        std::cout << "Enter department: ";
        getline(std::cin, employees[i].dept);

        std::cout << "Enter salary: ";
        std::cin >> employees[i].salary;

        std::cout << std::endl;
    }

    // Display slab 1 employees
    std::cout << "Slab 1 Employees:";
    for (size_t i=0; i<EMPLOYEES; i++)
        if (employees[i].salary <= 10000)
            displayEmployee(employees[i]);

    std::cout << std::endl;

    // Display slab 2 employees
    std::cout << "Slab 2 Employees:";
    for (size_t i=0; i<EMPLOYEES; i++)
        if (employees[i].salary > 50000)
            displayEmployee(employees[i]);

    std::cout << std::endl;

    // Display slab 3 employees
    std::cout << "Slab 3 Employees:";
    for (size_t i=0; i<EMPLOYEES; i++)
        if (employees[i].salary > 10000 && employees[i].salary < 50000)
            displayEmployee(employees[i]);

    return 0;
}

void displayEmployee(Employee employee) {
    std::cout <<                                       std::endl
              << "Employee #" << employee.empNo     << std::endl
              << "      Name : " << employee.name   << std::endl
              << "Department : " << employee.dept   << std::endl
              << "    Salary : " << employee.salary << std::endl;
}
