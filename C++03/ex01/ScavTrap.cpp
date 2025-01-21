#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name){
	std::cout << "ScavTrap " << this->getName() << " created" << std::endl;
	this->setStats(100, 50, 20);
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other._name){
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap&other){
	if (this == &other)
		return *this;

	this->_name = other._name;
	this->_hp = other._hp;
	this->_energy = other._energy;
	this->_damage = other._damage;
	ClapTrap::operator=(other);
	return *this;
}


void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName() << " is now in Gatekeeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->_energy == 0 && this->_hp > 0){
		std::cout	<< "ScavTrap " << this->_name << " is out of Energy Points and can't attack." \
					<< std::endl;
		return;
	}
	if (this->_hp > 0){
		this->_energy--;
		std::cout	<< "ScavTrap " << this->_name << " attacks " << target \
					<< ", causing " << this->_damage << " points of damage!" << std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount){
	if (this->_hp == 0){
		std::cout << this->_name << " is already dead. Stop this impudence!!" << std::endl;
		return;
	}
	this->_hp -= amount;
	if (this->_hp <= 0){
		this->_hp = 0;
		std::cout	<< "ScavTrap " << this->_name << " takes " << amount \
					<< " damage and now has " << this->_hp \
					<< " HP. -- RIP in pieces!" << std::endl;
		return;
	}
	std::cout	<< "ScavTrap " << this->_name << " takes " << amount \
				<< " damage and now has " << this->_hp << " HP." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount){
	if (this->_energy == 0 && this->_hp > 0){
		std::cout	<< "ScavTrap " << this->_name << " is out of Energy Points and can't heal." \
					<< std::endl;
		return;
	}
	if (this->_hp > 0){
		this->_energy--;
		this->_hp += amount;
		std::cout	<< "ScavTrap " << this->_name << " heals " << amount \
					<< " and now has " << this->_hp << " HP." << std::endl;
	}
}
