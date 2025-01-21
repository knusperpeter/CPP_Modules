#pragma once

# include "AForm.hpp"

class PresidentialPardonForm
: public AForm {
public:
	PresidentialPardonForm(std::string target = "default");
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm(){}

	void execute(Bureaucrat& bureaucrat) const;

private:
	std::string _target;
};