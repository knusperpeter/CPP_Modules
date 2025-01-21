#pragma once

# include "AForm.hpp"

class ShrubberyCreationForm
: public AForm {
public:
	ShrubberyCreationForm(std::string target = "default");
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(){}

	class CreationFailed : public std::exception {
		const char* what() const throw();
	};
	void execute(Bureaucrat& bureaucrat) const;

private:
	std::string _target;
};