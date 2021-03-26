/* [5] Write a program in C++ to handle the exception for the following inheritance
   structure. [Exception type must be class type]
 */

#include <iostream>

class Parent {
	protected:
	int p_age;

	public:
	class NegativeAgeException { };

	Parent(int age) {
		/* throws exception if age is <0 */

		if (age < 0)
			throw NegativeAgeException();

		this->p_age = age;
	}

	void read(void) {
		/* read the age */
		int age;

		std::cout << "Enter parent's age: ";
		std::cin >> age;

		if (age < 0)
			throw NegativeAgeException();

		p_age = age;
	}

	void write(void) {
		/* display age */
		std::cout << "Parent's Age : " << p_age << std::endl;
	}
};

class Child : public Parent {
	protected:
	int c_age;

	public:
	class OlderThanParentException { };

	Child(int p_age, int c_age) : Parent(p_age) {
		if (c_age > p_age)
			throw OlderThanParentException();

		this->c_age = c_age;
	}

	void read(void) {
		/* read the age */
		Parent::read();

		int age;

		std::cout << "Enter child's age: ";
		std::cin >> age;

		if (age > p_age)
			throw OlderThanParentException();

		c_age = age;
	}

	void write(void) {
		/* display age */
		Parent::write();
		std::cout << "Child's Age : " << c_age << std::endl;
	}
};

int main(void) {
	int p_age, c_age;

	std::cout << "Enter parent's age: ";
	std::cin >> p_age;
	std::cout << "Enter child's age: ";
	std::cin >> c_age;

	try {
		Child c_obj(p_age, c_age);
		c_obj.write();

	} catch(Parent::NegativeAgeException&) {
		std::cerr << "Parent's age cannot be negative!\n";
	} catch(Child::OlderThanParentException&) {
		std::cerr << "Child cannot be older than parent!\n";
	}

	return 0;
}
