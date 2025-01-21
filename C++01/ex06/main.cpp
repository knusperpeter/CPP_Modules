#include "Harl.hpp"

int main(int ac, char **av){
	if (ac != 2)
		return (std::cout << "wrong!" << std::endl, 1);
	Harl harl = Harl();
	std::string level = av[1];
	harl.complain(level);
	return 0;
}