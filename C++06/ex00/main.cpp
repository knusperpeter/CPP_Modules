#include "ScalarConverter.hpp"

int main(int ac, char** av){
	if (ac != 2){
		std::cerr << "please enter one argument" << std::endl;
		return 1;
	}
	std::string s = av[1];
	ScalarConverter::convert(s);
	return 0;
}