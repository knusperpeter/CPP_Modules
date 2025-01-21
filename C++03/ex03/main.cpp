#include "DiamondTrap.hpp"


int main(){
/* 	ClapTrap a;
	ClapTrap b("Malicious Mike");
	ClapTrap c("Normal Norman");
	ScavTrap d("Badboy Bele");
	ScavTrap e("Testing Tom");
	FragTrap f("Hansi Hinterseer");
	FragTrap g("Unsigned Uwe"); */
	DiamondTrap h("Daisy Diamond");
	DiamondTrap i;
	i = h;
	
	std::cout << std::endl;

	/* a.attack("Badboy Bele");
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

	f.highFivesGuys();
	g.attack("Badboy Bele");*/
	h.attack("someone");
	h.whoAmI();
	std::cout << std::endl;

	return 0;
}