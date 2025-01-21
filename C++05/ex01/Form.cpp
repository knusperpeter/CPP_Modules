#include "Form.hpp"

Form::Form(std::string name, int rts, int rte)
: _name(name), _signed(false), _required_to_sign(rts), _required_to_execute(rte) {
	if (_required_to_sign < 1 || _required_to_execute < 1)
		throw Form::GradeTooHighException();
	if (_required_to_sign > 150 || _required_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
: _name(other._name), _signed(other._signed), _required_to_sign(other._required_to_sign), _required_to_execute(other._required_to_execute) {
}

Form& Form::operator=(const Form& other){
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	return *this;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

const std::string & Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getRequiredToSign() const {
	return _required_to_sign;
}

int Form::getRequiredToExecute() const {
	return _required_to_execute;
}

void Form::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_required_to_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os	<< "Form name: " << form.getName() \
		<< " | Signed: " << (form.getSigned() ? "Yes" : "No") \
		<< " | Grade to sign: " << form.getRequiredToSign() \
		<< " | Grade to execute: " << form.getRequiredToExecute();
	return os;
}
