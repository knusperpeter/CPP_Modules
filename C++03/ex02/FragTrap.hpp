#pragma once

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class FragTrap : public ClapTrap{
public:
	FragTrap(std::string name = "Default Frag");
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap&other);
	~FragTrap(){std::cout << "FragTrap " << _name << " destroyed" << std::endl;}

	void highFivesGuys(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:

};
