#include "Fixed.hpp"

Fixed::Fixed() : Fixed_Point(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	Fixed_Point = other.getRawBits();
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other){
		std::cout << "Copy assignment operator called" << std::endl;
		this->Fixed_Point = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->Fixed_Point);
}

void Fixed::setRawBits( int const raw ){
	this->Fixed_Point = raw;
}