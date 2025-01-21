#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
: _type(type){}

AMateria::AMateria(const AMateria& other)
: _type(other._type){
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other){
	if (this == &other)
		return *this;

	this->_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const{
	return this->_type;
} //Returns the materia type

void AMateria::use(ICharacter& target){
	(void) target;
}
