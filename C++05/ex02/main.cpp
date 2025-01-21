#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	try{
		Bureaucrat anton("anton", 1);
		ShrubberyCreationForm s;
		RobotomyRequestForm r;
		PresidentialPardonForm p;
		anton.signForm(s);
		anton.executeForm(s);
		anton.signForm(r);
		anton.executeForm(r);
		anton.signForm(p);
		anton.executeForm(p);
	} catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

	try{
		Bureaucrat gustav("gustav", 10);
		ShrubberyCreationForm s;
		RobotomyRequestForm r;
		PresidentialPardonForm p;
		gustav.signForm(s);
		gustav.executeForm(s);
		gustav.signForm(r);
		gustav.executeForm(r);
		gustav.signForm(p);
		gustav.executeForm(p);
	} catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}