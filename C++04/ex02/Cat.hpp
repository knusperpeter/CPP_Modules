#pragma once

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);
	~Cat();
	Cat& operator=(const Cat& other);

	void makeSound() const;
	const std::string& getType() const;

private:
	Brain* _brain;
};
