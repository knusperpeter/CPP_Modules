#include "HumanB.hpp"

HumanB::HumanB(std::string name) : Name(name), Weapon_B(NULL){
	std::cout << Name << " created" << std::endl;
}

void HumanB::attack(){
	if (Weapon_B)
		std::cout << Name << " attacks with " << Weapon_B->getType() << std::endl;
	else
		std::cout << Name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
	Weapon_B = &weapon;
}