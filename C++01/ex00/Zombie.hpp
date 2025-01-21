#pragma once

# include <string>
# include <iostream>

class Zombie {

	public:
		Zombie();
		Zombie(std::string string);
		~Zombie();

		void announce();

	private:
		std::string name;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );