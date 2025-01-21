#include "WrongCat.hpp"

WrongCat::WrongCat(){
	type = "WrongCat";
	std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other){
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat sound" << std::endl;
}
