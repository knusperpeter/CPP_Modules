#pragma once

# include <string>
# include <iostream>

class Brain{
public:
	Brain(){std::cout << "Brain constructed" << std::endl;}
	Brain(const Brain& other);
	~Brain(){std::cout << "Brain destructed" << std::endl;}
	Brain& operator=(const Brain& other);

private:
	std::string ideas[100];
};