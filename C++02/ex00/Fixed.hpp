#pragma once

# include <string>
# include <iostream>

class Fixed{

	public:

		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:

		int Fixed_Point;
		static const int Fractional_Bits = 8;

};