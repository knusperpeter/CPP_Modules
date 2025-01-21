#pragma once

# include <string>
# include <iostream>

class ClapTrap{
public:
	ClapTrap(std::string name = "Default David");
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap(){std::cout << _name << " destroyed" << std::endl;}

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string	_name;
	int			_hp;
	int			_energy;
	int			_damage;
};