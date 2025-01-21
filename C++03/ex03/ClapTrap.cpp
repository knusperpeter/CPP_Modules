#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
: _name(name), _hp(10), _energy(10), _damage(0){
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this == &other)
		return *this;

	this->_name = other._name;
	this->_hp = other._hp;
	this->_energy = other._energy;
	this->_damage = other._damage;
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if (this->_energy == 0 && this->_hp > 0){
		std::cout	<< "ClapTrap " << this->_name << " is out of Energy Points and can't attack." \
					<< std::endl;
		return;
	}
	if(this->_hp > 0){
		this->_energy--;
		std::cout	<< "ClapTrap " << this->_name << " attacks " << target \
					<< ", causing " << this->_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hp == 0){
		std::cout << this->_name << " is already dead. Stop this impudence!!" << std::endl;
		return;
	}
	this->_hp -= amount;
	if (this->_hp <= 0){
		this->_hp = 0;
		std::cout	<< "ClapTrap " << this->_name << " takes " << amount \
					<< " damage and now has " << this->_hp \
					<< " HP. -- RIP in pieces!" << std::endl;
		return;
	}
	std::cout	<< "ClapTrap " << this->_name << " takes " << amount \
				<< " damage and now has " << this->_hp << " HP." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy == 0 && this->_hp > 0){
		std::cout	<< "ClapTrap " << this->_name << " is out of Energy Points and can't heal." \
					<< std::endl;
		return;
	}
	if(this->_hp > 0){
		this->_energy--;
		this->_hp += amount;
		std::cout	<< "ClapTrap " << this->_name << " heals " << amount \
					<< " and now has " << this->_hp << " HP." << std::endl;
	}
}

void ClapTrap::setStats(int hp, int energy, int damage){
	this->_hp = hp;
	this->_energy = energy;
	this->_damage = damage;
}

std::string ClapTrap::getName(){
	return this->_name;
}