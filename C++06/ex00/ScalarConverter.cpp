#include "ScalarConverter.hpp"

bool isInt(std::string& string){
	if (string.empty())
		return false;
	size_t i = 0;
	
	std::istringstream sso(string);
	std::cout << string << std::endl;
	long long value;
	char remaining;
	if (!(sso >> value) || sso.get(remaining))
		return false;
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		return false;
	return true;
}

bool convertToInt(std::string& string){
	if (isInt(string)){

	}
	return false;
}

bool convertToFloat(std::string& string){
	(void) string;
	return false;
}

bool convertToDouble(std::string& string){
	(void) string;
	return false;
}

bool convertToChar(std::string& string){
	std::istringstream stream(string);
	char c;
	if (stream >> c){
		std::cout << c << std::endl;
	}
	return false;
}

void ScalarConverter::convert(std::string& string){
	//string can be 0, 0.0f, a, 
	if (convertToInt(string))
		return;
	else if (convertToFloat(string))
		return;
	else if (convertToDouble(string))
		return;
	else if (convertToChar(string))
		return;
}