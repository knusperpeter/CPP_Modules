#pragma once

# include <string>
# include <iostream>
# include <exception>

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

	std::string const & getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	

private:
	const std::string	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);