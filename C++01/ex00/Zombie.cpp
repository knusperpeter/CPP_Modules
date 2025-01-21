#include "Zombie.hpp"

Zombie::Zombie() : name("default"){
	std::cout << name << " got created" << std::endl;
}

Zombie::Zombie(std::string string){
	name = string;
	std::cout << name << " got created" << std::endl;
}

Zombie::~Zombie(){
	std::cout << name << " got destoryed" << std::endl;
}

void Zombie::announce(){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}