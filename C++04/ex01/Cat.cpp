#include "Cat.hpp"

Cat::Cat()
: Animal("Cat"){
	_brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other)
: Animal("Cat"){
	*this = other;
}

Cat& Cat::operator=(const Cat& other){
	if (this == &other)
		return *this;

	Animal::operator=(other);
	this->type = other.type;
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructed" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

const std::string& Cat::getType() const {
	return (this->type);
}
