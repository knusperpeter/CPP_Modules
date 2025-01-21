#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <sstream>
# include <iostream>
#include <iomanip>
# include <limits.h>

class Contact {


public:

	Contact();

	bool Existant();
	void AddInfo(int index, std::string first_name, std::string last_name, std::string nickname, std::string phonenumber, std::string secret);
	void PrintInfo();
	void PrintContact();

private:

	bool Exists;
	int Index;
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string Secret;

	template <typename T>
	void PrintColumn(T data);
};

#endif