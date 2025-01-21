#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string name)
: type(name) {
	std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructed" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}

const std::string& WrongAnimal::getType() const{
	return type;
}
