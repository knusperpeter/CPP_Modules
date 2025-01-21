#include "Fixed.hpp"
#include <iomanip>

Fixed::Fixed() : Fixed_Point(0){
}

Fixed::Fixed(const int value){
	this->Fixed_Point = value << Fractional_Bits;
}

Fixed::Fixed(const float value){
	this->Fixed_Point = static_cast<double>(roundf(value * (1 << Fractional_Bits)));
}

Fixed::Fixed(const Fixed& other){
	*this = other;
}

Fixed::~Fixed(){
}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other){
		this->Fixed_Point = other.Fixed_Point;
	}
	return *this;
}




bool Fixed::operator>(const Fixed& other){
	if (this->Fixed_Point > other.Fixed_Point)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& other){
	if (this->Fixed_Point >= other.Fixed_Point)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& other){
	if (this->Fixed_Point < other.Fixed_Point)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& other){
	if (this->Fixed_Point <= other.Fixed_Point)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& other){
	if (this->Fixed_Point == other.Fixed_Point)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& other){
	if (this->Fixed_Point != other.Fixed_Point)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed& other){
	Fixed result;
	result.Fixed_Point = this->Fixed_Point + other.Fixed_Point;
	return result;
}

Fixed Fixed::operator-(const Fixed& other){
	Fixed result;
	result.Fixed_Point = this->Fixed_Point - other.Fixed_Point;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) {
    Fixed result;
    result.Fixed_Point = static_cast<int>((static_cast<long long>(this->Fixed_Point) * other.Fixed_Point) >> Fractional_Bits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other){
	long long i = (static_cast<long long> (this->Fixed_Point) << this->Fractional_Bits) / other.Fixed_Point;
	Fixed result(static_cast <float>(i) / (1 << this->Fractional_Bits));
	return result;
}

Fixed& Fixed::operator++(void){
	this->Fixed_Point++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed before(*this);
	this->Fixed_Point++;
	return before;
}

Fixed& Fixed::operator--(void){
	this->Fixed_Point--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed before(*this);
	this->Fixed_Point--;
	return before;
}

const Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2){
	if (fixed1.Fixed_Point <= fixed2.Fixed_Point)
		return fixed1;
	return fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2){
	if (fixed1.Fixed_Point <= fixed2.Fixed_Point)
		return fixed1;
	return fixed2;
}

const Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2){
	if (fixed1.Fixed_Point >= fixed2.Fixed_Point)
		return fixed1;
	return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2){
	if (fixed1.Fixed_Point >= fixed2.Fixed_Point)
		return fixed1;
	return fixed2;
}



float Fixed::toFloat( void ) const{
	return static_cast<float>(this->Fixed_Point) / (1 << Fractional_Bits);
}

int Fixed::toInt( void ) const{
	return this->Fixed_Point >> Fractional_Bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
	os << std::fixed << std::setprecision(6) << fixed.toFloat();
	return os;
}
