#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> vec;
	for (size_t i = 0; i < 5; i++){
		vec.insert(vec.begin(), i);
	}
	
    try {
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}