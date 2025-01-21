#include "Contact.hpp"

Contact::Contact() : Exists(false), Index(-1){}

bool Contact::Existant(){
	if (Exists == false)
		return false;
	return true;
}

void Contact::AddInfo(int index, std::string first_name, std::string last_name, std::string nickname, std::string phonenumber, std::string secret){
	Index = index;
	FirstName = first_name;
	LastName = last_name;
	PhoneNumber = phonenumber;
	Nickname = nickname;
	Secret = secret;
	Exists = true;
}

template <typename T>
void Contact::PrintColumn(T data){
	std::stringstream ss;
	ss << data;
	std::string dataStr = ss.str();
	if (dataStr.length() <= 10)
		std::cout << std::setw(10) << dataStr;
	else
		std::cout << std::setw(9) << dataStr.substr(0,9) << ".";
}

void Contact::PrintInfo(){
	PrintColumn(Index);
	std::cout	<< "|";
	PrintColumn(FirstName);
	std::cout	<< "|";
	PrintColumn(LastName);
	std::cout	<< "|";
	PrintColumn(Nickname);
	std::cout	<< std::endl;
}

void Contact::PrintContact(){
	std::cout	<< std::endl << FirstName << std::endl \
				<< LastName << std::endl \
				<< Nickname << std::endl \
				<< PhoneNumber << std::endl \
				<< Secret << std::endl << std::endl;
}