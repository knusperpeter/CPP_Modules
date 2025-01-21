#include "RPN.hpp"

int main(int ac, char** av){
	if (ac != 2)
		return std::cout << "Error: please provide one argument as a string" << std::endl, 1;

	std::stack<int, std::list<int> > nums;
	std::string input = av[1];
	bool next_is_space = false;
	for (std::string::iterator it = input.begin(); it != input.end(); ++it){
		if (*it == ' '){
			next_is_space = false;
			continue;
		}
		else if (std::isdigit(*it)){
			if (next_is_space)
				return std::cerr << "Error" << std::endl, 1;
			nums.push(*it - '0');
		}
		else if (isOperator(*it)){
			if (next_is_space)
				return std::cerr << "Error" << std::endl, 1;
			if (nums.size() < 2)
                return std::cerr << "Error" << std::endl, 1;
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            try {
                nums.push(calculate(b, a, *it));
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
            }
        } else {
            return std::cerr << "Error: invalid character" << std::endl, 1;
        }
		next_is_space = true;
    }
	if (nums.size() != 1)
		return std::cerr << "Error" << std::endl, 1;
	std::cout << nums.top() << std::endl;
	return 0;
}
