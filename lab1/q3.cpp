/*
 * Create an array of 5 structures named `Employee` with variables like (EmpNo, Name, Dept, Salary), input the details
   from keyboard and display it.
    a) Display the Average salary of the employees.
    b) Display the details of the employee having the highest salary.
 */
#include <iostream>

const size_t EMPLOYEES = 5;

typedef struct {
    size_t empNo;
    std::string name, dept;
    double salary;
} Employee;

void displayEmployee(Employee);

int main(void) {
    Employee employees[EMPLOYEES];
    double salSum, avgSalary;
    size_t maxSalEmpIndex = 0;

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

    // Display all employees
    for (size_t i=0; i<EMPLOYEES; i++)
        displayEmployee(employees[i]);

    // Determine average salary and employee having max. income
    for (size_t i=0; i<EMPLOYEES; i++) {
        salSum += employees[i].salary;
        if (employees[i].salary > employees[maxSalEmpIndex].salary)
            maxSalEmpIndex = i;
    }

    avgSalary = salSum / EMPLOYEES;
    std::cout << std::endl
              << "Average Salary : " << avgSalary << std::endl;

    std::cout << std::endl << "This employee have maximum salary:";
    displayEmployee(employees[maxSalEmpIndex]);

    return 0;
}

void displayEmployee(Employee employee) {
    std::cout <<                                       std::endl
              << "Employee #" << employee.empNo     << std::endl
              << "      Name : " << employee.name   << std::endl
              << "Department : " << employee.dept   << std::endl
              << "    Salary : " << employee.salary << std::endl;
}
