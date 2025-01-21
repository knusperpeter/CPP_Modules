#include "ClapTrap.hpp"

int main(){
	ClapTrap a = ClapTrap();
	ClapTrap b = ClapTrap("Badboy Bele");
	ClapTrap c = a;

	a.attack("Badboy Bele");
	b.takeDamage(0);
	a.beRepaired(1);
	b.attack("Clone of Default David");
	c.takeDamage(0);
	c.beRepaired(1);

	c.attack("someone else");
	return 0;
}