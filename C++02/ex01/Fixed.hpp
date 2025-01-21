#pragma once

# include <string>
# include <iostream>
# include <cmath>

class Fixed{

	public:

		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);

		float toFloat( void ) const;
		int toInt( void ) const;

	private:

		int Fixed_Point;
		static const int Fractional_Bits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);