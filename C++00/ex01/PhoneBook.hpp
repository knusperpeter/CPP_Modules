#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Contact.hpp"

class PhoneBook {
public:

	PhoneBook();

	void Init();
	bool AddContact(int i);
	void SearchContact();

private:

	Contact contact[8];
};

void replace_tabs(std::string& fn, std::string& ln, std::string& nn, std::string& pn, std::string& se);

#endif