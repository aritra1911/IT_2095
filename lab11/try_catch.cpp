/* [1] Write a program in C++ to illustrate the following:
   > General flow of try-catch block
   > Use of generalized exception handler
   > Re-throwing exceptions
   > Specifying Exceptions
   > Exception type as primary type and user defined type
   > Life time of an object within a try block
   > A function caller handling the exception
   > Nested try blocks
   > Multiple catch and catch all
*/

#include <iostream>

class UserDefinedException { };

class Test {
	void display() {
		std::cout << "Inside Test\n";
	}
};

void throwException(void) {
	throw UserDefinedException();
}

int main(void) {
	try {
		try {
			Test t();  // Object created inside of `try { }' block
			throwException();
			std::cout << "This statement is never reached!\n";
		} catch (int e) {
			std::cout << "Int Exception caught!\n";
			std::cout << "Rethrowing...\n";
			throw e;
		} catch (UserDefinedException e) {
			//t.display();  // Error: t is not accessible outside of its scope
			std::cout << "UserDefinedException caught!\n";
			std::cout << "Rethrowing...\n";
			throw e;
		}
	} catch (...) {
		std::cout << "Generalized exception caught!\n";
	}

	return 0;
}
