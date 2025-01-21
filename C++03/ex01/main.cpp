#include "ScavTrap.hpp"


int main(){
	ClapTrap a;
	ClapTrap b("Malicious Mike");
	ClapTrap c = a;
	ScavTrap d("Badboy Bele");
	ScavTrap e("Testing Tom");
	std::cout << std::endl;

	a.attack("Badboy Bele");
	b.takeDamage(0);
	a.beRepaired(1);
	b.attack("Clone of Default David");
	c.takeDamage(0);
	c.beRepaired(1);
	c.attack("someone else");
	std::cout << std::endl;

	d.takeDamage(20);
	d.attack(e.getName());
	e.takeDamage(20);
	e.beRepaired(1);
	e.attack("someone else");
	e.guardGate();
	std::cout << std::endl;

	return 0;
}