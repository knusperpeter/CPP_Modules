#include <iostream>
#include <string>

int main(){
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Address in memory of the string: " << &string << std::endl;
    std::cout << "Address in memory of the stringPTR: " << stringPTR << std::endl;
    std::cout << "Address in memory of the stringREF: " << &stringREF << std::endl;

    std::cout << "Value pointed to by String: " << string << std::endl;
    std::cout << "Value pointed to by StringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by StringREF: " << stringREF << std::endl;
    return 0;
}