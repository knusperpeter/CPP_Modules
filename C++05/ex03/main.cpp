#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern intern;

        // Test cases
        AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
        if (form1) {
            std::cout << "Created form: " << form1->getName() << std::endl;
            delete form1;
        }

        AForm* form2 = intern.makeForm("robotomy request", "Robot");
        if (form2) {
            std::cout << "Created form: " << form2->getName() << std::endl;
            delete form2;
        }

        AForm* form3 = intern.makeForm("presidential pardon", "President");
        if (form3) {
            std::cout << "Created form: " << form3->getName() << std::endl;
            delete form3;
        }

        // Test with an unknown form name
        AForm* form4 = intern.makeForm("unknown form", "Unknown");
        if (!form4) {
            std::cout << "Failed to create form: unknown form" << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}