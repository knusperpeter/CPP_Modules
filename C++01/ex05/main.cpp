#include "Harl.hpp"

int main(){
	Harl harl = Harl();
	std::string level;
	while (true){
		std::cout << "Enter Level:            (type \"exit\" once you heard enough of Harls bullshit)" << std::endl;
		std::getline(std::cin, level);
		std::cout << "  Harl:" << std::endl;
		harl.complain(level);
		if (level == "exit")
			break;
	}
	return 0;
}