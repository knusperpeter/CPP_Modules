#include "AForm.hpp"

AForm::AForm(std::string name, int rts, int rte)
: _name(name), _signed(false), _required_to_sign(rts), _required_to_execute(rte) {
	if (_required_to_sign < 1 || _required_to_execute < 1)
		throw AForm::GradeTooHighException();
	if (_required_to_sign > 150 || _required_to_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other._name), _signed(other._signed), _required_to_sign(other._required_to_sign), _required_to_execute(other._required_to_execute) {
}

AForm& AForm::operator=(const AForm& other){
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

const char* AForm::ExecuteError::what() const throw(){
	return "Form is not signed or bureaucrat's grade is too low to execute";
}


const std::string & AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getRequiredToSign() const {
	return _required_to_sign;
}

int AForm::getRequiredToExecute() const {
	return _required_to_execute;
}

void AForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_required_to_sign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form){
	os	<< "AForm name: " << form.getName() \
		<< " | Signed: " << (form.getSigned() ? "Yes" : "No") \
		<< " | Grade to sign: " << form.getRequiredToSign() \
		<< " | Grade to execute: " << form.getRequiredToExecute();
	return os;
}