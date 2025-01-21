#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
	*this = other;
}

Intern& Intern::operator=(const Intern& other){
	if (this == &other)
		return *this;

	return *this;
}

const char* Intern::UnknownForm::what() const throw(){
	return "The intern does not know this form";
}

const int SHRUBBERY_CREATION = 0;
const int ROBOTOMY_REQUEST = 1;
const int PRESIDENTIAL_PARDON = 2;
const int UNKNOWN_FORM = -1;

struct FormPair {
	const char* name;
	int type;
};

const FormPair formMap[] = {
	{"shrubbery creation", SHRUBBERY_CREATION},
	{"robotomy request", ROBOTOMY_REQUEST},
	{"presidential pardon", PRESIDENTIAL_PARDON}
};

int getFormType(const std::string& name){
	for (size_t i = 0; i < sizeof(formMap) / sizeof(FormPair); i++){
		if (name == formMap[i].name)
			return formMap[i].type;
	}
	return UNKNOWN_FORM;
}

AForm* Intern::makeForm(std::string name, std::string target){
	std::cout << "Intern creates " << name << std::endl;
	switch (getFormType(name)){
		case SHRUBBERY_CREATION:
			return new ShrubberyCreationForm(target);
		case ROBOTOMY_REQUEST:
			return new RobotomyRequestForm(target);
		case PRESIDENTIAL_PARDON:
			return new PresidentialPardonForm(target);
		default:
			throw Intern::UnknownForm();
	}
}