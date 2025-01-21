#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : Name(name), Weapon_A(weapon){
	std::cout << Name << " created" << std::endl;
}

void HumanA::attack(){
	std::cout << Name << " attacks with " << Weapon_A.getType() << std::endl;
}

void HumanA::setWeapon(Weapon& weapon){
	Weapon_A = weapon;
}