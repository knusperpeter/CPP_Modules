#include "PmergeMe.hpp"

void only_positive_integers(int ac, char **av){
	for (int i = 1; i < ac; ++i){
		long long value = atoll(av[i]);
		if (value > std::numeric_limits<int>::max())
			throw std::runtime_error("input contains a number higher than int max");
		if (value < 0)
			throw std::runtime_error("input contains a negative number");
		char *ptr = av[i];
		while (*ptr){
			if (!isdigit(*ptr) || !*ptr){
				throw std::runtime_error("input contains a non-numeric argument");
			}
			ptr++;
		}
	}
}

//	-	-	-	-	-	DEQUE FUNCTIONS	-	-	-	-	-	-	-	-	-	-

std::deque<int> sort_deque(PmergeMe& container, size_t level){
	size_t csize = pow(2, level);
	if (csize > container.deque.size())
		return container.deque;
	container.swap_ranges_deque(csize, true);
//	container.print_deque(csize, container.deque);
	return sort_deque(container, level + 1);
}

void insert_chunk_deque(size_t jacobsthal, size_t index, size_t csize, PmergeMe& container){
	size_t chunk_pos = (index - 1) * csize;
	std::deque<int>::iterator chunk_start = container.b_deque.begin() + chunk_pos;
	size_t dist = std::min(static_cast<size_t>((pow(2, jacobsthal) - 1) * csize), container.mc_deque.size());
	std::deque<int>::iterator container_end = container.mc_deque.begin() + dist;
	std::deque<int>::iterator pos = container.binary_search(container.mc_deque.begin(), container_end, *chunk_start, csize);
	chunk_start = container.b_deque.begin() + chunk_pos;
	std::deque<int>::iterator chunk_end = chunk_start + csize;
	container.mc_deque.insert(pos, chunk_start, chunk_end);
}

std::deque<int> sort_back_deque(PmergeMe& container, int level){
	size_t csize = pow(2, level);
	if (level < 0)
		return container.deque;

	if (container.uneven != -1 && csize == 1)
		container.deque.push_back(container.uneven);
	if (2 * csize <= container.deque.size()){
		container.split_deque(csize);
/*		container.print_deque(csize, container.deque);
 		std::cout << RED << "main: " << RESET;
		container.print_deque(csize, container.mc);
		std::cout << RED << "b   : " << RESET;
		container.print_deque(csize, container.b); */
		container.mc_deque.insert(container.mc_deque.begin(), container.b_deque.begin(), container.b_deque.begin() + csize);

		std::vector<size_t> jacobsthal_sequence;
		jacobsthal_sequence.push_back(1);
		jacobsthal_sequence.push_back(1);
		size_t next_jacob = 3;
		while (jacobsthal_sequence.back() < container.b_deque.size() / csize){
			next_jacob = jacobsthal_sequence.back() + jacobsthal_sequence[jacobsthal_sequence.size() - 2] * 2;
			jacobsthal_sequence.push_back(next_jacob);
		}

		for (size_t i = 2; i < jacobsthal_sequence.size(); ++i){
			size_t index = jacobsthal_sequence[i];

			if (index >= container.b_deque.size() / csize){
				while (index > container.b_deque.size() / csize)
					--index;
			}

			insert_chunk_deque(i, index, csize, container);

			if (index != 1){
				--index;
				while (index > jacobsthal_sequence[i - 1]){
					insert_chunk_deque(i, index, csize, container);
					--index;
				}
			}
		}
		container.deque = container.mc_deque;
		for (size_t i = 0; i < container.rest_deque.size(); ++i)
			container.deque.push_back(container.rest_deque[i]);
		container.mc_deque.clear();
		container.b_deque.clear();
		container.rest_deque.clear();
	}
	return sort_back_deque(container, level - 1);
}

void main_chain_deque(PmergeMe& container){
	size_t level = 0;
	while (container.deque.size() >= (2 * pow(2, level)))
		level++;
//	std::cout << YELLOW << "Second sort: " << RESET << std::endl;
	container.deque = sort_back_deque(container, level - 1);
	return;
}

//	-	-	-	-	-	VECTOR FUNCTIONS	-	-	-	-	-	-	-	-	-	-

std::vector<int> sort_vector(PmergeMe& container, size_t level){
	size_t csize = pow(2, level);
	if (csize > container.vector.size())
		return container.vector;
	container.swap_ranges_vector(csize, true);
//	container.print_vector(csize, container.vector);
	return sort_vector(container, level + 1);
}

void insert_chunk_vector(size_t jacobsthal, size_t index, size_t csize, PmergeMe& container){
	size_t chunk_pos = (index - 1) * csize;
	std::vector<int>::iterator chunk_start = container.b_vector.begin() + chunk_pos;
	size_t dist = std::min(static_cast<size_t>((pow(2, jacobsthal) - 1) * csize), container.mc_vector.size());
	std::vector<int>::iterator container_end = container.mc_vector.begin() + dist;
	std::vector<int>::iterator pos = container.binary_search(container.mc_vector.begin(), container_end, *chunk_start, csize);
	chunk_start = container.b_vector.begin() + chunk_pos;
	std::vector<int>::iterator chunk_end = chunk_start + csize;
	container.mc_vector.insert(pos, chunk_start, chunk_end);
}

std::vector<int> sort_back_vector(PmergeMe& container, int level){
	size_t csize = pow(2, level);
	if (level < 0)
		return container.vector;

	if (container.uneven != -1 && csize == 1)
		container.vector.push_back(container.uneven);
	if (2 * csize <= container.vector.size()){
		container.split_vector(csize);
/*		container.print_vector(csize, container.vector);
 		std::cout << RED << "main: " << RESET;
		container.print_vector(csize, container.mc_vector);
		std::cout << RED << "b   : " << RESET;
		container.print_vector(csize, container.b_vector); */
		container.mc_vector.insert(container.mc_vector.begin(), container.b_vector.begin(), container.b_vector.begin() + csize);

		std::vector<size_t> jacobsthal_sequence;
		jacobsthal_sequence.push_back(1);
		jacobsthal_sequence.push_back(1);
		size_t next_jacob = 3;
		while (jacobsthal_sequence.back() < container.b_vector.size() / csize){
			next_jacob = jacobsthal_sequence.back() + jacobsthal_sequence[jacobsthal_sequence.size() - 2] * 2;
			jacobsthal_sequence.push_back(next_jacob);
		}

		for (size_t i = 2; i < jacobsthal_sequence.size(); ++i){
			size_t index = jacobsthal_sequence[i];

			if (index >= container.b_vector.size() / csize){
				while (index > container.b_vector.size() / csize)
					--index;
			}

			insert_chunk_vector(i, index, csize, container);

			if (index != 1){
				--index;
				while (index > jacobsthal_sequence[i - 1]){
					insert_chunk_vector(i, index, csize, container);
					--index;
				}
			}
		}
		container.vector = container.mc_vector;
		for (size_t i = 0; i < container.rest_vector.size(); ++i)
			container.vector.push_back(container.rest_vector[i]);
		container.mc_vector.clear();
		container.b_vector.clear();
		container.rest_vector.clear();
	}
	return sort_back_vector(container, level - 1);
}

void main_chain_vector(PmergeMe& container){
	size_t level = 0;
	while (container.vector.size() >= (2 * pow(2, level)))
		level++;
//	std::cout << YELLOW << "Second sort: " << RESET << std::endl;
	container.vector = sort_back_vector(container, level - 1);
	return;
}

void control_function(PmergeMe container){
	std::deque<int>::iterator it = container.deque.begin();
	int tmp = *it;
	++it;
	for (; it != container.deque.end(); ++it){
		if (tmp > *it){
			std::cout << "not sorted correctly" << std::endl;
			return;
		}
		tmp = *it;
	}

	std::vector<int>::iterator itv = container.vector.begin();
	int tmpv = *itv;
	++it;
	for (; itv != container.vector.end(); ++itv){
		if (tmpv > *itv){
			std::cout << "not sorted correctly" << std::endl;
			return;
		}
		tmpv = *itv;
	}
}

int main(int ac, char **av){
	if (ac < 3)
		return std::cerr << "Error: not enough arguments" << std::endl, 1;
	try {
		only_positive_integers(ac, av);
		int count = ac - 1;
		PmergeMe container;
		for (int i = 0; i < count; ++i) container.deque.push_back(atoi(av[i + 1]));
		for (int i = 0; i < count; ++i) container.vector.push_back(atoi(av[i + 1]));
		std::cout << "Before:  ";
		container.print_deque(3, container.deque);




//	-	-	-	-	-	-	-	DEQUE	-	-	-	-	-	-	-	-	-	-	-	-

		struct timeval start, end;
		gettimeofday(&start, NULL);
		if (container.deque.size() % 2 == 1){
			container.uneven = *(container.deque.end() - 1);
			container.deque.pop_back();
		}
	//	std::cout << YELLOW << "First sort: " << RESET << std::endl;
		container.deque = sort_deque(container, 0);
		main_chain_deque(container);

		gettimeofday(&end, NULL);
		long seconds = end.tv_sec - start.tv_sec;
		long microseconds = end.tv_usec - start.tv_usec;
		long duration = seconds * 1000000 + microseconds;

		std::cout << "After:   ";
		container.print_deque(3, container.deque);




//	-	-	-	-	-	-	-	VECTOR	-	-	-	-	-	-	-	-	-	-	-	-
		struct timeval start_vector, end_vector;
		gettimeofday(&start_vector, NULL);
		if (container.vector.size() % 2 == 1){
			container.vector.pop_back();
		}
	//	std::cout << YELLOW << "First sort: " << RESET << std::endl;
		container.vector = sort_vector(container, 0);
		main_chain_vector(container);

		gettimeofday(&end_vector, NULL);
		long seconds_vector = end_vector.tv_sec - start_vector.tv_sec;
		long microseconds_vector = end_vector.tv_usec - start_vector.tv_usec;
		long duration_vector = seconds_vector * 1000000 + microseconds_vector;




//	-	-	-	-	-	-	-	MONITORING	-	-	-	-	-	-	-	-	-	-	-	-	-

	//	std::cout << "Container size: " << container.deque.size() << std::endl;
	//	control_function(container);
	//	std::cout << "Comparisons:" << comparisons << std::endl;
		std::cout << "Time to process " << container.deque.size() << " elements with std::deque:  " << duration << " us" << std::endl;
		std::cout << "Time to process " << container.vector.size() << " elements with std::vector: " << duration_vector << " us" << std::endl;
	} catch(std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}