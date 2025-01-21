#include "Bureaucrat.hpp"

int main() {
    // Test 1: Default constructor and decrement
    try {
        Bureaucrat i;
        i.decrement();
        std::cout << i << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 2: Parameterized constructor and increment
    try {
        Bureaucrat j("Felix", 1);
        j.increment();
        std::cout << j << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 3: Grade too high exception
    try {
        Bureaucrat k("High", 0);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 4: Grade too low exception
    try {
        Bureaucrat l("Low", 151);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 5: Increment causing grade too high exception
    try {
        Bureaucrat m("Almost High", 2);
        m.increment();
        m.increment();
        std::cout << m << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 6: Decrement causing grade too low exception
    try {
        Bureaucrat n("Almost Low", 149);
        n.decrement();
        n.decrement();
        std::cout << n << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}