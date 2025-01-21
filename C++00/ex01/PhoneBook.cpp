#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	Init();
}

bool PhoneBook::AddContact(int i){
	i %= 8;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phonenumber;
	std::string secret;
	std::cin.ignore();
	std::cout	<< "Enter firstname: ";
	if (!std::getline(std::cin, first_name))
		return(std::cerr << "Invalid input" << std::endl, false);
	std::cout	<< "Enter lastname: ";
	if (!std::getline(std::cin, last_name))
		return(std::cerr << "Invalid input" << std::endl, false);
	std::cout	<< "Enter nickname: ";
	if (!std::getline(std::cin, nickname))
		return(std::cerr << "Invalid input" << std::endl, false);
	std::cout	<< "Enter phone number: ";
	if (!std::getline(std::cin, phonenumber))
		return(std::cerr << "Invalid input" << std::endl, false);
	std::cout	<< "Enter darkest secret: ";
	if (!std::getline(std::cin, secret))
		return(std::cerr << "Invalid input" << std::endl, false);
	replace_tabs(first_name, last_name, nickname, phonenumber, secret);
	contact[i].AddInfo(i, first_name, last_name, nickname, phonenumber, secret);
	return true;
}

void PhoneBook::Init(){
	for (int i = 0; i < 8; i++)
		contact[i] = Contact();
}

void PhoneBook::SearchContact(){
	if (!contact[0].Existant()){
		std::cout << "No saved contacts." << std::endl;
		return;
	}
	std::cout << "Index     |Firstname |Lastname  |Nickname  " << std::endl;
	for (int i = 0; i < 8 && contact[i].Existant(); i++)
		contact[i].PrintInfo();
	while (!std::cin.eof()){
		std::string index;
		std::cout << "Enter Index: ";
		std::cin >> index;
		if (index.length() == 1 && index.at(0) >= '0' && index.at(0) <= '7'){
			int num = index.at(0) - '0';
			if (contact[num].Existant()){
				contact[num].PrintContact();
				return;
			}
		} 
		std::cout << "Please enter the index of an added contact (0 - 7)" << std::endl;
	}
}

void replace_tabs(std::string& fn, std::string& ln, std::string& nn, std::string& pn, std::string& se){
	size_t pos;
	while ((pos = fn.find("\t")) != std::string::npos){
		fn.erase(pos, 1);
		fn.insert(pos, "    ");
	}
	while ((pos = ln.find("\t")) != std::string::npos){
		ln.erase(pos, 1);
		ln.insert(pos, "    ");
	}
	while ((pos = nn.find("\t")) != std::string::npos){
		nn.erase(pos, 1);
		nn.insert(pos, "    ");
	}
	while ((pos = pn.find("\t")) != std::string::npos){
		pn.erase(pos, 1);
		pn.insert(pos, "    ");
	}
	while ((pos = se.find("\t")) != std::string::npos){
		se.erase(pos, 1);
		se.insert(pos, "    ");
	}
}