#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other){
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	if (this == &other)
		return *this;

	for (int i = 0; i < 4; i++){
		if (this->_slots[i])
			delete this->_slots[i];
		if (other._slots[i])
			this->_slots[i] = other._slots[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		delete _slots[i];
	}
}


void MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < 4; i++){
		if (!this->_slots[i]){
			this->_slots[i] = materia;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (_slots[i] && _slots[i]->getType() == type)
			return _slots[i]->clone();
	}
	return NULL;
}
