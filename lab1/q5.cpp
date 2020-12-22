/*
 * Do the Q3 by passing a pointer to the array of Employee structures inside the functions. Functions are
 *      a) Input()
 *      b) Display()
 *      c) Average()
 *      d) Highest()
 */
#include <iostream>

const size_t EMPLOYEES = 5;

typedef struct {
    size_t empNo;
    std::string name, dept;
    double salary;
} Employee;

void input(Employee*);
void display(const Employee*);
void average(const Employee*);
void highest(const Employee*);
void displayEmployee(const Employee&);

int main(void) {
    Employee* employees = new Employee[EMPLOYEES];

    input(employees);
    display(employees);
    average(employees);
    highest(employees);

    delete[] employees;

    return 0;
}

void input(Employee* employee) {
    for (size_t i=0; i<EMPLOYEES; i++) {
        std::cout << "Enter employee no.: ";
        std::cin >> employee->empNo;

        std::cin.ignore(10, '\n');  // eat chars, including newline

        std::cout << "Enter name: ";
        getline(std::cin, employee->name);

        std::cout << "Enter department: ";
        getline(std::cin, employee->dept);

        std::cout << "Enter salary: ";
        std::cin >> employee->salary;

        std::cout << std::endl;
        employee++;
    }
}

void display(const Employee* employee) {
    for (size_t i=0; i<EMPLOYEES; i++)
        displayEmployee(*employee++);
}

void average(const Employee* employee) {
    double salSum = 0.0f;

    for (size_t i=0; i<EMPLOYEES; i++)
        salSum += (employee++)->salary;

    std::cout << std::endl << "Average Salary : "
              << (salSum / EMPLOYEES) << std::endl;
}

void highest(const Employee* employee) {
    const Employee* maxSalEmp = employee++;

    for (size_t i=0; i<EMPLOYEES; i++) {
        if (employee->salary > maxSalEmp->salary)
            maxSalEmp = employee;

        employee++;
    }

    std::cout << std::endl << "Highest paid employee :";
    displayEmployee(*maxSalEmp);
}

void displayEmployee(const Employee &employee) {
    std::cout <<                                       std::endl
              << "Employee #" << employee.empNo     << std::endl
              << "      Name : " << employee.name   << std::endl
              << "Department : " << employee.dept   << std::endl
              << "    Salary : " << employee.salary << std::endl;
}
