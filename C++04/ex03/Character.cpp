#include "Character.hpp"

Character::Character(std::string name) : _name(name){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other){
	*this = other;
}

Character& Character::operator=(const Character& other){
	if (this == &other)
		return *this;

	this->_name = other._name;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++){
		if (!_inventory[i]){
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx){
	if (idx < 4 && idx >= 0)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if(idx < 4 && idx >= 0 && _inventory[idx])
		_inventory[idx]->use(target);
}
