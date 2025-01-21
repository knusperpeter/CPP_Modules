#include "PhoneBook.hpp"

int main(){
	std::ostream &o = std::cout;
	PhoneBook PhoneBook;
	PhoneBook.Init();
	std::string input;
	int i = 0;
	while (!std::cin.eof())
	{
		o << "╔══════════════════════════════════╗"<< std::endl;
		o << "║Select Option: ADD, SEARCH or EXIT║" << std::endl;
		o << "╠══════════════════════════════════╝"<< std::endl << "╚";
		std::cin >> input;
		if (!input.compare("ADD"))
			PhoneBook.AddContact(i++);
		else if (!input.compare("SEARCH"))
			PhoneBook.SearchContact();
		else if (!input.compare("EXIT"))
			break;
		else
			o << "Try again! It's not that complicated" << std::endl;
	}
	return 0;
}
