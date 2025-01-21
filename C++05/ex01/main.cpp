#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    // Test 1: Valid Form creation
    try {
        Form form1("Form1", 50, 100);
        std::cout << form1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 2: Grade too high exception for signing
    try {
        Form form2("Form2", 0, 100);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 3: Grade too high exception for executing
    try {
        Form form3("Form3", 50, 0);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 4: Grade too low exception for signing
    try {
        Form form4("Form4", 151, 100);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 5: Grade too low exception for executing
    try {
        Form form5("Form5", 50, 151);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 6: Copy constructor
    try {
        Form form6("Form6", 50, 100);
        Form form7(form6);
        std::cout << form7 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 7: Assignment operator
    try {
        Form form8("Form8", 50, 100);
        Form form9("Form9", 60, 110);
        form9 = form8;
        std::cout << form9 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 8: Bureaucrat signing a form (successful)
    try {
        Bureaucrat bureaucrat1("John Doe", 40);
        Form form10("Form10", 50, 100);
        bureaucrat1.signForm(form10);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 9: Bureaucrat signing a form (unsuccessful due to low grade)
    try {
        Bureaucrat bureaucrat2("Jane Doe", 60);
        Form form11("Form11", 50, 100);
        bureaucrat2.signForm(form11);
		std::cout << form11 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 10: Form being signed directly (successful)
    try {
        Bureaucrat bureaucrat3("Alice", 40);
        Form form12("Form12", 50, 100);
        form12.beSigned(bureaucrat3);
        std::cout << form12 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 11: Form being signed directly (unsuccessful due to low grade)
    try {
        Bureaucrat bureaucrat4("Bob", 60);
        Form form13("Form13", 50, 100);
        form13.beSigned(bureaucrat4);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}