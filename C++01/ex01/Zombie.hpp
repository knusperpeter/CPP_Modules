#pragma once

# include <string>
# include <iostream>

class Zombie {

	public:
		Zombie();
		Zombie(const std::string string);
		~Zombie();

		void announce();
		void setName(std::string name);

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );