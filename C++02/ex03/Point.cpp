#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(Fixed()), _y(Fixed()){
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)){
}

Point::Point(const Point& other) : _x(other._x), _y(other._y){
}

Point::~Point(){
}

Point& Point::operator=(const Point& other){
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}