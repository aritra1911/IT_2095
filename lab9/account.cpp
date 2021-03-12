/* Q3) Create a class Account which stores account number, customer name and balance. Derive two
   classes   `Savings' and `Current' from `Account' class:  The `Savings' class has a minimum balance of rs 1000. The
   `Current' class has a min balance amount of rs 5000. Include member functions in the appropriate class for
   -deposit money
   -withdraw (minimum balance should be checked)
   -display balance
   Display data from each class using virtual function.
*/

#include <iostream>

class Account {
    protected:
    unsigned int account_number;
    char customer_name[64];
    int balance;

    public:
    void read_data() {
        std::cout << "Enter account number: ";
        std::cin >> account_number;
        std::cin.ignore(10, '\n');  // eat chars, including newline
        std::cout << "Enter customer name: ";
        std::cin.getline(customer_name, 64, '\n');
        std::cout << "Enter balance: ";
        std::cin >> balance;
    }

    void deposit(int amount) {
        balance += amount;
        std::cout << amount << " has been deposited. You balance is now " << balance << std::endl;
    }

    virtual void withdraw(int) = 0;

    void display() {
        std::cout << "Account Number : " << account_number << std::endl
                  << "Customer Name : " << customer_name << std::endl
                  << "Balance : " << balance << std::endl;
    }
};

class Savings : public Account {
    public:
    void withdraw(int amount) {
        if (balance - amount < 1000) {
            std::cerr << "Cannot withdraw, minimum amount is 1000\n";
            return;
        }

        balance -= amount;
        std::cout << amount << " has been withdrawn. You balance is now " << balance << std::endl;
    }
};

class Current : public Account {
    public:
    void withdraw(int amount) {
        if (balance - amount < 5000) {
            std::cerr << "Cannot withdraw, minimum amount is 5000\n";
            return;
        }

        balance -= amount;
        std::cout << amount << " has been withdrawn. You balance is now " << balance << std::endl;
    }
};

int main(void) {
    Account* acc;
    Savings sav;
    Current curr;

    acc = &sav;
    acc->read_data();
    std::cout << std::endl;
    acc = &curr;
    acc->read_data();

    std::cout << std::endl;

    acc->deposit(6000);
    acc->withdraw(200);
    acc->withdraw(2000);

    std::cout << std::endl;

    acc = &sav;
    acc->deposit(2000);
    acc->withdraw(100);
    acc->withdraw(1000);

    return 0;
}
