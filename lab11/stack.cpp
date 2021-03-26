/* [4] Write a program in C++ to handle the exception for underflow and overflow in
   case of a Stack ADT. [Exception type must be class type]
 */

#include <iostream>

const int DEFAULT_STACK_SIZE = 10;

class Stack {
	int* stack;
	int top, size;

	public:
	class OverflowException { };
	class UnderflowException { };

	Stack(int size = DEFAULT_STACK_SIZE) {
		stack = new int[size];
		this->size = size;
		this->top = -1;
	}

	bool is_full(void) {
		if (top >= size - 1)
			return true;

		return false;
	}

	bool is_empty(void) {
		if (top < 0)
			return true;

		return false;
	}

	void push(int n) {
		if (this->is_full())
			throw OverflowException();

		stack[++top] = n;
	}

	int pop(void) {
		if (this->is_empty())
			throw UnderflowException();

		return stack[top--];
	}

	~Stack(void) {
		delete[] stack;
	}
};

int main(void) {
	Stack my_stack(15);

	try {
		for (int i = 0; i < 20; i++) {
			std::cout << "PUSH : " << i << std::endl;
			my_stack.push(i);
		}

	} catch (Stack::OverflowException) {
		std::cerr << "Stack overflow!\n";
	}

	try {
		for (int i = 0; i < 20; i++)
			std::cout << "POP : " << my_stack.pop() << std::endl;

	} catch (Stack::UnderflowException) {
		std::cerr << "Stack underflow!\n";
	}

	return 0;
}
