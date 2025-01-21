#pragma once

# include <iostream>
# include <string>
# include <limits>
# include <sstream>

class ScalarConverter {
public:
	static void convert(std::string& string);

private:
	ScalarConverter(){}
	ScalarConverter(const  ScalarConverter& other){(void)other;}
	~ScalarConverter(){}
	ScalarConverter& operator=(const ScalarConverter& other){(void)other; return *this;}
};