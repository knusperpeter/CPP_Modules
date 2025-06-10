#include "PmergeMe.hpp"

int comparisons = 0;

//	-	-	-	-	-	-	DEQUE	-	-	-	-	-	-	-	-

void PmergeMe::print_deque(size_t csize, std::deque<int> deque){
	size_t j = 1;
	for (std::deque<int>::iterator i = deque.begin(); i != deque.end(); i++){
		std::cout << *i << " ";
		if (j % csize == 0 && csize != 3)
			std::cout << MAGENTA << "| " << RESET;
		j++;
	}
	std::cout << std::endl;
}

void PmergeMe::swap_ranges_deque(size_t csize, bool compare){
	for (size_t i = 0; (i + (2 * csize)) <= deque.size(); i += (2 * csize)){
		std::deque<int>::iterator first1 = deque.begin() + i;
		std::deque<int>::iterator last = first1 + csize;
		std::deque<int>::iterator first2 = first1 + csize;
		if (compare){
			if (*first1 < *first2)
				std::swap_ranges(first1, last, first2);
			comparisons++;
		}
		else
			std::swap_ranges(first1, last, first2);
	}
}

void PmergeMe::split_deque(size_t csize){
	bool push_b = false;
	bool check = false;
	size_t deque_size = deque.size();
	for (size_t i = 0; i < deque_size; i += csize){

		size_t remaining = deque_size - i;
		size_t chunk_end = std::min(i + csize, deque_size);
		
		if ((remaining < (2 * csize) && remaining > csize) || ((deque_size / csize) % 2 == 1 && i == deque_size - csize)){
			push_b = true;
			check = true;
			for (size_t j = i + csize; j < deque_size; ++j){
				rest_deque.push_back(deque[j]);
			}
		}

		for (size_t j = i; j < chunk_end; ++j){
			if (!push_b)
				mc_deque.push_back(deque[j]);
			else {
				b_deque.push_back(deque[j]);
			}
		}
		if (check)
			break;
		push_b = !push_b;
	}
}

//	-	-	-	-	-	-	VECTOR	-	-	-	-	-	-	-	-

void PmergeMe::print_vector(size_t csize, std::vector<int> vector){
	size_t j = 1;
	for (std::vector<int>::iterator i = vector.begin(); i != vector.end(); i++){
		std::cout << *i << " ";
		if (j % csize == 0 && csize != 3)
			std::cout << MAGENTA << "| " << RESET;
		j++;
	}
	std::cout << std::endl; 
}

void PmergeMe::swap_ranges_vector(size_t csize, bool compare){
	for (size_t i = 0; (i + (2 * csize)) <= vector.size(); i += (2 * csize)){
		std::vector<int>::iterator first1 = vector.begin() + i;
		std::vector<int>::iterator last = first1 + csize;
		std::vector<int>::iterator first2 = first1 + csize;
		if (compare){
			if (*first1 < *first2)
				std::swap_ranges(first1, last, first2);
		//	comparisons++;
		}
		else
			std::swap_ranges(first1, last, first2);
	}
}

void PmergeMe::split_vector(size_t csize){
	bool push_b = false;
	bool check = false;
	size_t vector_size = vector.size();
	for (size_t i = 0; i < vector_size; i += csize){

		size_t remaining = vector_size - i;
		size_t chunk_end = std::min(i + csize, vector_size);
		
		if ((remaining < (2 * csize) && remaining > csize) || ((vector_size / csize) % 2 == 1 && i == vector_size - csize)){
			push_b = true;
			check = true;
			for (size_t j = i + csize; j < vector_size; ++j){
				rest_vector.push_back(vector[j]);
			}
		}

		for (size_t j = i; j < chunk_end; ++j){
			if (!push_b)
				mc_vector.push_back(vector[j]);
			else {
				b_vector.push_back(vector[j]);
			}
		}
		if (check)
			break;
		push_b = !push_b;
	}
}


size_t PmergeMe::jacobsthal(size_t n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

template <class Iterator>
Iterator PmergeMe::binary_search(Iterator begin, Iterator end, size_t n, size_t csize){
	Iterator last_valid = begin;
	bool found_larger = false;

	while (begin != end) {
		size_t dist = std::distance(begin, end);
		if (dist < csize)
			return found_larger ? last_valid : begin;

		size_t mid_offset = ((dist / csize) / 2) * csize;

		if (mid_offset == 0){
            if (is_deque == true)
			    comparisons++;
//			std::cout << BLUE << "Return condition: begin: " << YELLOW << *begin << BLUE << " end: " << YELLOW << *end << BLUE << ", n: " << YELLOW << int(n) << RESET << std::endl;
			if (*begin > int(n))
				return begin;
			return end;
		}

		Iterator mid = begin;
		std::advance(mid, mid_offset);
//		std::cout << BLUE << "n = " << YELLOW << n << BLUE << " begin: " << *begin << " end: " << *end << " offset: " << mid_offset << " mid: " << *mid << RESET << std::endl;
		if (*mid > int(n)){
			found_larger = true;
			end = mid;
			last_valid = mid;
		}
		else
			begin = mid + csize;
		if (is_deque == true)
			    comparisons++;
	}
	return found_larger ? last_valid : begin;
}

template std::deque<int>::iterator PmergeMe::binary_search<std::deque<int>::iterator>(std::deque<int>::iterator, std::deque<int>::iterator, size_t, size_t);
template std::vector<int>::iterator PmergeMe::binary_search<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator, size_t, size_t);