#pragma once

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name = "Default Scav");
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap&other);
	~ScavTrap(){std::cout << "ScavTrap " << _name << " destroyed" << std::endl;}

	void guardGate();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
