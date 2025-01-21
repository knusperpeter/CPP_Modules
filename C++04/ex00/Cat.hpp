#pragma once

# include <string>
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);
	~Cat(){std::cout << "Cat destructed" << std::endl;}

	Cat& operator=(const Cat& other);
	void makeSound() const;
	const std::string& getType() const;
};