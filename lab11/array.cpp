/* [3] Write a program in C++ to handle the exception for array-out-of-bound.
   [Exception type must be class type]
 */

#include <iostream>

class Array {
	int* arr;
	int size;

	public:
	class IndexOutOfBoundsException { };

	Array(int size) {
		this->size = size;
		this->arr = new int[this->size];
	}

	int& operator [](int index) {
		if (index < 0 || index >= size)
			throw IndexOutOfBoundsException();

		return arr[index];
	}

	~Array(void) {
		delete[] arr;
	}
};

int main(void) {
	Array a(10);

	try {
		a[0] = 15;
		std::cout << "a[0] : " << a[0] << std::endl;
		a[3] = 24;
		std::cout << "a[3] : " << a[3] << std::endl;
		a[11] = 45;
		std::cout << "a[11] : " << a[11] << std::endl;
	} catch (Array::IndexOutOfBoundsException&) {
		std::cerr << "Index Out Of Bounds!\n";
	}

	return 0;
}
