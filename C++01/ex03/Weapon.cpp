#include "Weapon.hpp"

Weapon::Weapon(){
	std::cout << "Weapon created" << std::endl;
}

Weapon::Weapon(std::string weapontype){
	type = weapontype;
	std::cout << "Weapon " << type << " created" << std::endl;
}

const std::string& Weapon::getType() const {
	return type;
}

void Weapon::setType(std::string string){
	type = string;
}