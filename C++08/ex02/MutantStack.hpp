#pragma once

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
public:
	MutantStack(){};
	MutantStack(const MutantStack& other){ *this = other; }
	MutantStack& operator=(const MutantStack& other);
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::iterator reverse_iterator;

	iterator begin(){
		return std::stack<T>::c.begin();
	}

	iterator end(){
		return std::stack<T>::c.end();
	}

	reverse_iterator rbegin(){
		return std::stack<T>::c.rbegin();
	}

	reverse_iterator rend(){
		return std::stack<T>::c.rend();
	}
};

# include "MutantStack.tpp"