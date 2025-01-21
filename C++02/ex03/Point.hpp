#pragma once

# include "Fixed.hpp"

class Point{
	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		~Point();
		Point& operator=(const Point& other);

		Fixed getX() const;
		Fixed getY() const;

	private:
		const Fixed _x;
		const Fixed _y;

};