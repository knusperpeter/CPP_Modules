#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Zombie got created" << std::endl;
}

Zombie::Zombie(const std::string string) : name(string){
    std::cout << "Zombie " << name << " got created" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << name << " got destoryed" << std::endl;
}

void Zombie::announce(){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}