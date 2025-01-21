#include "Span.hpp"

Span::Span(unsigned int N){
	nums.reserve(N);
}

Span::Span(const Span& other){
	*this = other;
}

Span& Span::operator=(const Span& other){
	if (this == &other)
		return *this;
	this->nums = other.nums;
	return *this;
}

void Span::addNumber(int i){
	if (nums.capacity() > nums.size()){
		nums.insert(nums.end(), i);
		return;
	}
	throw std::runtime_error("Space is full");
}

unsigned int Span::shortestSpan(){
	if (nums.size() < 2)
		throw std::runtime_error("Not enough elements");
	std::vector<int> sorted(nums);
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sorted.size(); ++i){
		if (minSpan > (unsigned int)(sorted[i]) - sorted[i - 1])
			minSpan = (unsigned int)(sorted[i]) - sorted[i - 1];
	}
	return minSpan;
}

unsigned int Span::longestSpan(){
	if (nums.size() < 2)
		throw std::runtime_error("Not enough elements");
	unsigned int min = *std::min_element(nums.begin(), nums.end());
	unsigned int max = *std::max_element(nums.begin(), nums.end());
	return max - min;
}