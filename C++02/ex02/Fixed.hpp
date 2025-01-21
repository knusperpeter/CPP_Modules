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
		
		bool operator>(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);

		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);

		Fixed& operator++(void);
		Fixed operator++(int);

		Fixed& operator--(void);
		Fixed operator--(int);

		static const Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);

		static const Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

		float toFloat( void ) const;
		int toInt( void ) const;

	private:

		int Fixed_Point;
		static const int Fractional_Bits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);