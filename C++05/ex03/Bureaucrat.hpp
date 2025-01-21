#pragma once

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;
class Bureaucrat{
public:
	Bureaucrat(std::string name = "Basic Barbara", int grade = 150);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat(){}

	class GradeTooHighException : public std::exception{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
	public:
		const char* what() const throw();	
	};

	const std::string & getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signForm(AForm& form);
	void executeForm(AForm const & form);
	

private:
	const std::string	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);