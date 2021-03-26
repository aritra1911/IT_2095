/* [2] Write a program in C++ to handle the exception for divide-by-zero error.
   [Exception type must be class type]
 */

#include <iostream>

int divide(int, int);

class DivideByZeroException { };

int main(void) {
	int x, y;

	std::cout << "Enter operands of division: ";
	std::cin >> x >> y;

	try {
		std::cout << "Result : " << divide(x, y) << std::endl;
	} catch (DivideByZeroException&) {
		std::cout << "Cannot divide when divisor is zero.\n";
	}

	return 0;
}

int divide(int x, int y) {
	if (y == 0)
		throw DivideByZeroException();

	return x / y;
}
