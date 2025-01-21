#include "Cure.hpp"

Cure::Cure()
: AMateria("cure"){}

Cure::Cure(const Cure& other)
: AMateria("cure"){
	*this = other;
}

Cure& Cure::operator=(const Cure& other){
	if (this == &other)
		return *this;

	AMateria::operator=(other);
	this->_type = other._type;
	return *this;
}

AMateria* Cure::clone() const{
	Cure* copy = new Cure();
	return copy;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
