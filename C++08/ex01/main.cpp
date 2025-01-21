#include "Span.hpp"
#include <iostream>
#include <vector>

void testAddMultipleNumbers() {
	try {
		Span sp(10);
		std::vector<int> numbers;
		for (int i = 0; i < 5; ++i) numbers.push_back(i);
		sp.addNumbers(numbers.begin(), numbers.end());

		// Check if the numbers were added correctly
		std::cout << "Numbers added successfully: ";
		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// Add more numbers
		std::vector<int> moreNumbers;
		for (int i = 5; i < 10; ++i) moreNumbers.push_back(i);
		sp.addNumbers(moreNumbers.begin(), moreNumbers.end());

		// Check if the additional numbers were added correctly
		std::cout << "More numbers added successfully: ";
		for (std::vector<int>::iterator it = moreNumbers.begin(); it != moreNumbers.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	try {
		Span sp(5);
		sp.addNumber(2147483647);
		sp.addNumber(-2147483648);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		int arr[] = {6, 7, 8};
		std::vector<int> moreNumbers;
		for (int i = 0; i < 3; ++i) moreNumbers.push_back(arr[i]);
		sp.addNumbers(moreNumbers.begin(), moreNumbers.end());

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span sp(11474);
		for (int i = 0; i < 11474; i++) {
			sp.addNumber(i);
		}

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	testAddMultipleNumbers();

	return 0;
}