#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm("PresidentialPardonForm", 25, 5){
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this == &other)
		return *this;

	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat& bureaucrat) const{
	if (!this->getSigned() || bureaucrat.getGrade() > this->getRequiredToExecute()){
		throw AForm::ExecuteError();
	}
	std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}