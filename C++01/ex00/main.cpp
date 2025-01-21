#include "Zombie.hpp"

int main(){
	randomChump("Tom");
	Zombie *Josef = newZombie("Josef");
	Josef->announce();
	delete Josef;
	return 0;
}