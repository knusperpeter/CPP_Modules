#pragma once

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
	ScavTrap(std::string name = "Default Scav");
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap&other);
	~ScavTrap(){std::cout << "ScavTrap " << _name << " destroyed" << std::endl;}

	virtual void guardGate();
	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);

protected:
	static const int hp = 100;
	static const int energy = 50;
	static const int damage = 20;
};
