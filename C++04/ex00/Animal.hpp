#pragma once

# include <string>
# include <iostream>

class Animal{
public:
	Animal(std::string name = "Generic Goose");
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal(){std::cout << "Animal destructed" << std::endl;}

	virtual void makeSound() const;
	virtual const std::string& getType() const;

protected:
	std::string type;
};