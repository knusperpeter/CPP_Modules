#include "Span.hpp"

template<typename I>
void Span::addNumbers(I start, I end){
	if (nums.capacity() >= std::distance(start, end) + nums.size())
		return nums.insert(nums.end(), start, end);
	throw std::runtime_error("Out of range");
}