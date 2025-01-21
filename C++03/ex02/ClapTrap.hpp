#pragma once

# include <string>
# include <iostream>

class ClapTrap{
public:
	ClapTrap(std::string name = "Default Clap");
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap(){std::cout << "ClapTrap " << _name << " destroyed" << std::endl;}

	virtual	void attack(const std::string& target);
	virtual	void takeDamage(unsigned int amount);
	virtual	void beRepaired(unsigned int amount);
	void setStats(int hp, int energy, int damage);
	std::string getName();

protected:
	std::string	_name;
	int			_hp;
	int			_energy;
	int			_damage;
};
