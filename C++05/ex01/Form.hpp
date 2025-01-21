#pragma once

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form{
public:
	Form(std::string n = "Flawless Form", int rts = 1, int rte = 1);
	Form(const Form& other);
	~Form(){}
	Form& operator=(const Form& other);

	class GradeTooHighException : public std::exception{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
	public:
		const char* what() const throw();
	};

	const std::string & getName() const;
	bool getSigned() const;
	int getRequiredToSign() const;
	int getRequiredToExecute() const;
	void beSigned(Bureaucrat& bureaucrat);

private:
	const std::string _name;
	bool _signed;
	const int _required_to_sign;
	const int _required_to_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);