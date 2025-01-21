#pragma once

# include <iostream>
# include <vector>
# include <exception>
# include <iterator>
# include <algorithm>
# include <limits>

//std::min_element
//std::sort

class Span {
public:
	Span(unsigned int N = 0);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span(){}


	template<typename I>
	void addNumbers(I start, I end);
	void addNumber(int i);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	
private:
	std::vector<int> nums;
};

# include "Span.tpp"