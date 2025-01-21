#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name") , ScavTrap(name), FragTrap(name), _name(name){
	this->_hp = FragTrap::hp;
	this->_energy = ScavTrap::energy;
	this->_damage = FragTrap::damage;
	//std::cout << _hp << " " << _energy << " " << _damage << std::endl;
	std::cout << "DiamondTrap " << this->_name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other._name + "_clap_name") , ScavTrap(other._name), FragTrap(other._name), _name(other._name){
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap&other){
	if (this != &other){
		this->_name = other._name;
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
	}
	return *this;
}


void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap: " << this->_name << "\nClapTrap: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    ScavTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
	ScavTrap::beRepaired(amount);
}