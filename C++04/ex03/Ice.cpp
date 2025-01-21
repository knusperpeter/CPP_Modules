#include "Ice.hpp"

Ice::Ice()
: AMateria("ice"){}

Ice::Ice(const Ice& other)
: AMateria("ice"){
	*this = other;
}

Ice& Ice::operator=(const Ice& other){
	if (this == &other)
		return *this;

	AMateria::operator=(other);
	this->_type = other._type;
	return *this;
}

AMateria* Ice::clone() const{
	Ice* copy = new Ice();
	return copy;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
