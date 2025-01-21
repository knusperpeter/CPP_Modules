#pragma once

# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm
: public AForm {
public:
	RobotomyRequestForm(std::string target = "default");
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm(){}

	class RandomizationFailed : public std::exception {
		const char* what() const throw();
	};
	void execute(Bureaucrat& bureaucrat) const;

private:
	std::string _target;
};