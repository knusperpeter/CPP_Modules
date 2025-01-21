#include "Fixed.hpp"

Fixed::Fixed() : Fixed_Point(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	this->Fixed_Point = value << Fractional_Bits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	this->Fixed_Point = static_cast<int>(roundf(value * (1 << Fractional_Bits)));
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other){
		std::cout << "Copy assignment operator called" << std::endl;
		this->Fixed_Point = other.Fixed_Point;
	}
	return *this;
}

float Fixed::toFloat( void ) const{
	return static_cast<float>(this->Fixed_Point) / (1 << Fractional_Bits);
}

int Fixed::toInt( void ) const{
	return this->Fixed_Point >> Fractional_Bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return os;
}
