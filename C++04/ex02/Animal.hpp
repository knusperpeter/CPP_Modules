#pragma once

# include <string>
# include <iostream>

class Animal{
public:
	Animal(std::string name = "Generic Giraffe");
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal(){std::cout << "Animal destructed" << std::endl;}

	virtual void makeSound() const = 0;
	virtual const std::string& getType() const = 0;

protected:
	std::string type;
};