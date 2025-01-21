#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name){
	try{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(std::exception& i){
		std::cout << i.what() << std::endl;
		return;
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this == &other)
		return *this;

	//this->_name = other._name;
	this->_grade = other._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

void Bureaucrat::increment(){
	try{
		if (this->_grade - 1 < 1)
			throw(Bureaucrat::GradeTooHighException());
		this->_grade--;
	}
	catch(std::exception& i){
	std::cout << i.what() << std::endl;
		return;	}
}

void Bureaucrat::decrement(){
	try{
		if (this->_grade + 1 > 150)
			throw(Bureaucrat::GradeTooLowException());
		this->_grade++;
	}
	catch(std::exception& i){
	std::cout << i.what() << std::endl;
		return;
	}
}


const std::string & Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::signForm(Form& form){
	try {
		form.beSigned(*this);
		if (form.getSigned())
			std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " beacause " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
	return os;
}