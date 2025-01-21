#pragma once

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <map>
# include <stdlib.h>
# include <iomanip>
# include <exception>

struct Date{
	int year;
	std::string syear;
	int month;
	std::string smonth;
	int day;
	std::string sday;
};

bool parse_data(std::map<int, float> *exchange_rate);
void get_valid_date(Date *date, std::string line);
void is_valid_date(Date date);
bool convert_input(std::map<int, float> *exchange_rate, char* filename);
