#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
: ClapTrap(name){
	std::cout << "FragTrap " << this->getName() << " created" << std::endl;
	this->setStats(100, 100, 30);
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other._name){
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap&other){
	if (this == &other)
		return *this;

	this->_name = other._name;
	this->_hp = other._hp;
	this->_energy = other._energy;
	this->_damage = other._damage;
	ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->getName() << ": High Five, Guys!" << std::endl;
}


void FragTrap::attack(const std::string& target){
	if (this->_energy == 0 && this->_hp > 0){
		std::cout	<< "FragTrap " << this->_name << " is out of Energy Points and can't attack." \
					<< std::endl;
		return;
	}
	if (this->_hp > 0){
		this->_energy--;
		std::cout	<< "FragTrap " << this->_name << " attacks " << target \
					<< ", causing " << this->_damage << " points of damage!" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount){
	if (this->_hp == 0){
		std::cout << this->_name << " is already dead. Stop this impudence!!" << std::endl;
		return;
	}
	this->_hp -= amount;
	if (this->_hp <= 0){
		this->_hp = 0;
		std::cout	<< "FragTrap " << this->_name << " takes " << amount \
					<< " damage and now has " << this->_hp \
					<< " HP. -- RIP in pieces!" << std::endl;
		return;
	}
	std::cout	<< "FragTrap " << this->_name << " takes " << amount \
				<< " damage and now has " << this->_hp << " HP." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount){
	if (this->_energy == 0 && this->_hp > 0){
		std::cout	<< "FragTrap " << this->_name << " is out of Energy Points and can't heal." \
					<< std::endl;
		return;
	}
	if (this->_hp > 0){
		this->_energy--;
		this->_hp += amount;
		std::cout	<< "FragTrap " << this->_name << " heals " << amount \
					<< " and now has " << this->_hp << " HP." << std::endl;
	}
}