#include "Zombie.hpp"

int main(){
	Zombie* zombies = zombieHorde(2, "Josef");
    delete [] zombies;
	return 0;
}