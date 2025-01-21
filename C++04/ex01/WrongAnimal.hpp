#pragma once

# include <string>
# include <iostream>

class WrongAnimal{
public:
	WrongAnimal(std::string name = "Wrong Wolf");
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	void makeSound() const;
	const std::string& getType() const;

protected:
	std::string type;
};