#pragma once

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
public:
	FragTrap(std::string name = "Default Scav");
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap&other);
	~FragTrap(){std::cout << "FragTrap " << _name << " destroyed" << std::endl;}

	virtual void highFivesGuys(void);
	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);

protected:
	static const int hp = 100;
	static const int energy = 100;
	static const int damage = 30;
};
