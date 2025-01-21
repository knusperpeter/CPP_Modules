#pragma once

# include <string>
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& other);
	~Dog(){std::cout << "Dog destructed" << std::endl;}

	Dog& operator=(const Dog& other);
	void makeSound() const ;
	const std::string& getType() const;
};