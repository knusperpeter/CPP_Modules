#pragma once

# include <iostream>
# include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F funcptr){
	for (size_t i = 0; i < length; ++i){
		funcptr(array[i]);
	}
};