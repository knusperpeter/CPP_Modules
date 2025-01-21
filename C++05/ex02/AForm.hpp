#pragma once

# include <string>
# include <iostream>
# include <fstream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm{
public:
	AForm(std::string n = "Flawless Form", int rts = 1, int rte = 1);
	AForm(const AForm& other);
	virtual ~AForm(){}
	AForm& operator=(const AForm& other);

	class GradeTooHighException : public std::exception{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
	public:
		const char* what() const throw();
	};

	class ExecuteError : public std::exception {
		const char* what() const throw();
	};

	const std::string & getName() const;
	bool getSigned() const;
	int getRequiredToSign() const;
	int getRequiredToExecute() const;
	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat& bureaucrat) const = 0;


private:
	const std::string _name;
	bool _signed;
	const int _required_to_sign;
	const int _required_to_execute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);