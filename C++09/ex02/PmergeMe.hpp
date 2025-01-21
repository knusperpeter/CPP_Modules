#pragma once

# include <iostream>
# include <algorithm>
# include <deque>
# include <limits>
# include <cstdlib>
# include <exception>
# include <utility>
# include <cmath>
# include <vector>
# include <sys/time.h>

# define RESET		"\033[0m"
# define BLUE		"\033[34m"
# define RED		"\033[31m"
# define YELLOW		"\033[33m"
# define MAGENTA	"\033[35m"

extern int comparisons;

class PmergeMe {
public:
	PmergeMe(){uneven = -1;}

	std::deque<int> deque;
	std::deque<int> mc_deque;
	std::deque<int> b_deque;
	std::deque<int> rest_deque;
	std::vector<int> vector;
	std::vector<int> mc_vector;
	std::vector<int> b_vector;
	std::vector<int> rest_vector;
	int uneven;


	void print_deque(size_t csize, std::deque<int> deque);
	void swap_ranges_deque(size_t csize, bool compare);
	void split_deque(size_t csize);

	void print_vector(size_t csize, std::vector<int> vector);
	void swap_ranges_vector(size_t csize, bool compare);
	void split_vector(size_t csize);

	size_t jacobsthal(size_t n);
	template<class Iterator>
	static Iterator binary_search(Iterator begin, Iterator end, size_t n, size_t csize);
};