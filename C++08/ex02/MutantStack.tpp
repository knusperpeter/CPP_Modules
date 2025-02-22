#include "MutantStack.hpp"

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other){
	if (this == &other)
		return *this;
	std::stack<T>::operator=(other);
	return *this;
}