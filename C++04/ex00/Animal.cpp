#include "Animal.hpp"

Animal::Animal(std::string name)
: type(name) {
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal& other){
	*this = other;
}

Animal& Animal::operator=(const Animal& other){
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

const std::string& Animal::getType() const{
	return type;
}
