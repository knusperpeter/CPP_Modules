#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm("ShrubberyCreationForm", 145, 137){
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this == &other)
		return *this;

	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

const char* ShrubberyCreationForm::CreationFailed::what() const throw(){
	return "Failed to create file";
}

void ShrubberyCreationForm::execute(Bureaucrat& bureaucrat) const{
	if (!this->getSigned() || bureaucrat.getGrade() > this->getRequiredToExecute()){
		throw AForm::ExecuteError();
	}
	std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;

	std::ofstream outFile((_target + "_shrubbery").c_str());
	if (!outFile)
		throw ShrubberyCreationForm::CreationFailed();
	outFile << "       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\n       }|{" << std::endl;
	outFile.close();
}