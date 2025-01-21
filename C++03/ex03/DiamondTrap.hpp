#pragma once

# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
public:
	DiamondTrap(std::string name = "Default Diamond");
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap&other);
	~DiamondTrap(){std::cout << "DiamondTrap " << this->_name << " destroyed" << std::endl;}

	void whoAmI();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	std::string _name;
};