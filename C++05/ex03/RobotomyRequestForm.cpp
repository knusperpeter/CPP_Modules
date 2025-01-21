#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm("RobotomyRequestForm", 72, 45){
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this == &other)
		return *this;

	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

const char* RobotomyRequestForm::RandomizationFailed::what() const throw(){
	return "Randomization failed";
}

void RobotomyRequestForm::execute(Bureaucrat& bureaucrat) const{
	if (!this->getSigned() || bureaucrat.getGrade() > this->getRequiredToExecute()){
		throw AForm::ExecuteError();
	}
	std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;

	int random = (int)std::time(0) % 2;
	std::cout << "*drill* *drilllll*" << std::endl;
	switch (random){
		case 0:
			std::cout << _target << " has been robotomized successfully" << std::endl;
			break;
		case 1:
			std::cout << _target << " robotomy failed" << std::endl;
			break;
		default:
			throw RandomizationFailed();
	}
}