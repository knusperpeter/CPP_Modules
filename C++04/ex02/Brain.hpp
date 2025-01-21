#pragma once

# include <string>
# include <iostream>

class Brain{
public:
	Brain(){std::cout << "Brain constructed" << std::endl;}
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain(){std::cout << "Brain destructed" << std::endl;}

private:
	std::string ideas[100];
};