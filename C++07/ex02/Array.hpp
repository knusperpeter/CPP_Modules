#pragma once

# include <iostream>
# include <exception>

template<typename T>
class Array{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	T& operator[](unsigned int index);
	~Array(){delete[] _data;}

	unsigned int size() const;
private:
	unsigned int _size;
	T* _data;
};

# include "Array.tpp"