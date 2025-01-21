#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& t, int i){
	typename T::iterator it = std::find(t.begin(), t.end(), i);
	if (*it == i)
		return it;
	throw std::runtime_error("Element not found");
}