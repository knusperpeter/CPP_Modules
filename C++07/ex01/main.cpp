#include "iter.hpp"

template<typename T>
void pelement(T& element) {
	std::cout << element << " ";
}

template<typename T>
void increment(T& element) {
	++element;
}

int main(){
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	iter<int, void(*)(int&)>(intArray, 5, increment<int>);
	iter<int, void(*)(int&)>(intArray, 5, pelement<int>);
	std::cout << std::endl;
	iter<double, void(*)(double&)>(doubleArray, 5, increment<double>);
	iter<double, void(*)(double&)>(doubleArray, 5, pelement<double>);
	std::cout << std::endl;
	iter<char, void(*)(char&)>(charArray, 5, increment<char>);
	iter<char, void(*)(char&)>(charArray, 5, pelement<char>);
	std::cout << std::endl;
	return 0;
}
