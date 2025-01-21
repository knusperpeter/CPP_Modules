#pragma once

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& other);
	~Dog();
	Dog& operator=(const Dog& other);

	void makeSound() const ;
	const std::string& getType() const;

private:
	Brain* _brain;
};