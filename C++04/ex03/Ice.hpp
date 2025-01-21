#pragma once

# include <string>
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice(){}

	AMateria* clone() const;
	void use(ICharacter& target);

protected:
	std::string _type;
};
