#pragma once

# include "AForm.hpp"

class Intern{
public:
	Intern();
	Intern(const Intern& other);
	~Intern(){}
	Intern& operator=(const Intern& other);

	class UnknownForm : public std::exception {
		const char* what() const throw();
	};

	AForm* makeForm(std::string name, std::string target);
};