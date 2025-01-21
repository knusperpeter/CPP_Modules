#include "Array.hpp"

int main(){
	// Test default constructor
	Array<int> defaultArray;
	std::cout << "Default array size: " << defaultArray.size() << std::endl;

	// Test parameterized constructor
	Array<int> paramArray(5);
	std::cout << "Parameterized array size: " << paramArray.size() << std::endl;

	// Test element assignment and access
	for (unsigned int i = 0; i < paramArray.size(); ++i) {
		paramArray[i] = i * 2;
	}

	std::cout << "Parameterized array elements: ";
	for (unsigned int i = 0; i < paramArray.size(); ++i) {
		std::cout << paramArray[i] << " ";
	}
	std::cout << std::endl;

	// Test copy constructor
	Array<int> copyArray(paramArray);
	std::cout << "Copy array elements: ";
	for (unsigned int i = 0; i < copyArray.size(); ++i) {
		std::cout << copyArray[i] << " ";
	}
	std::cout << std::endl;

	// Test assignment operator
	Array<int> assignArray;
	assignArray = paramArray;
	std::cout << "Assigned array elements: ";
	for (unsigned int i = 0; i < assignArray.size(); ++i) {
		std::cout << assignArray[i] << " ";
	}
	std::cout << std::endl;

	// Test out of range exception
	try {
		std::cout << "Accessing out of range element: " << paramArray[9] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}