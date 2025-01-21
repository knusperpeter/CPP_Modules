#include "BitcoinExchange.hpp"

bool only_numeric(char c, int amount, std::string s){
	bool invalid = false;
	for (std::string::iterator it = s.begin(); it != s.end(); ++it){
		int character = 0;
		if (!isdigit(*it) && *it != c){
			invalid = true;
			break;
		}
		if (*it == '.')
			++character;
		if (character > amount){
			invalid = true;
			break;
		}
	}
	if (invalid)
		return false;
	return true;
}

bool parse_data(std::map<int, float> *exchange_rate){
	std::ifstream data("data.csv");
	if (!data.is_open())
		return std::cerr << "Error: file could not be opened" << std::endl, false;

	std::string line;
	while (std::getline(data, line)){
		if (line == "date,exchange_rate")
			std::getline(data, line);
		std::stringstream stream(line);
		std::string date;
		float value;
		int formated_date;

		if (std::getline(stream, date, ',')){
			std::string cleaned_date;
			for (std::string::iterator it = date.begin(); it != date.end(); ++it){
				if (*it != '-')
					cleaned_date += *it;
			}
			stream >> value;
			if (stream.fail())
				std::cerr << "Error: conversion failed" << std::endl;

			std::stringstream datestream(cleaned_date);
			datestream >> formated_date;
			if (formated_date < 20090102)
				return std::cerr << "Error: invalid date" << std::endl, false;
			exchange_rate->insert(std::pair<int, float>(formated_date, value));
		}
	}
	return true;
}

void get_valid_date(Date *date, std::string line){
	date->syear = line.substr(0, 4);
	date->year = std::atoi(date->syear.c_str());
	date->smonth = line.substr(5, 2);
	date->month = std::atoi(date->smonth.c_str());
	date->sday = line.substr(8, 2);
	date->day = std::atoi(date->sday.c_str());
	if (!only_numeric('-', 2, line) || line.size() < 1)
		throw std::runtime_error("Error: invalid date input: ");
}

void is_valid_date(Date date){
	bool leap_year = false;

	if (date.day < 1 || date.month < 1 || date.year < 2009)
		throw std::runtime_error("Error: bad input => ");
	if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)
		leap_year = true;
	if ((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) && date.day > 31)
		throw std::runtime_error("Error: bad input => ");
	else if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30)
		throw std::runtime_error("Error: bad input => ");
	else if (leap_year && date.month == 2 && date.day > 29)
		throw std::runtime_error("Error: bad input => ");
	else if (!leap_year && date.month == 2 && date.day > 28)
		throw std::runtime_error("Error: bad input => ");

}

bool convert_input(std::map<int, float> *exchange_rate, char* filename){
	std::ifstream input(filename);
	if (!input.is_open())
		return std::cerr << "Error: File can not be opened" << std::endl, false;

	std::string line;
	std::getline(input, line);
	if (line != "date | value"){
		std::cerr << "Error: file needs \"date | value\" in first line" << std::endl;
		return false;
	}
	while (std::getline(input, line)){
		std::stringstream stream(line);
		std::string date_str, value_str;

		if (std::getline(stream, date_str, '|') && std::getline(stream, value_str)){
			Date date;
			try{
				if (*(date_str.end() - 1) != ' ')
					throw std::runtime_error("Error: invalid input: ");
				if (date_str.size() > 10)
					date_str.erase(date_str.size() - 1, 1);
				get_valid_date(&date, date_str);
				is_valid_date(date);
			} catch (const std::exception& e){
				std::cerr << e.what() << date_str << std::endl;
				continue;
			}

			try{
				if (*(value_str.begin()) != ' ')
					throw std::runtime_error("Error: invalid input: ");
			} catch (const std::exception& e){
				std::cerr << e.what() << line << std::endl;
				continue;
			}
			
			
			value_str.erase(0, 1);

			if (!only_numeric('.', 1, value_str) || value_str.size() < 1){
				std::cerr << "Error: not a valid number" << std::endl;
				continue;
			}
			float value;
			std::stringstream value_stream(value_str);
			value_stream >> value;
			if (value_stream.fail() || value > 1000 || value < 0){
				std::cerr << "Error: value out of range" << std::endl;
				continue;
			}
			int formatted_date = date.year * 10000 + date.month * 100 + date.day;

			std::map<int, float>::iterator it = exchange_rate->lower_bound(formatted_date);
			if (it == exchange_rate->end() || it->first != formatted_date) {
				if (it != exchange_rate->begin())
					--it;
				else {
					std::cerr << "Error: no valid date found for " << date_str << std::endl;
					continue;
				}
			}
			std::cout << date.syear << "-" << date.smonth << "-" << date.sday << " => " << value << " = " << value * it->second << std::endl;;
		}
		if (value_str.empty()){
			std::cerr << "Error: bad input => " << date_str << std::endl;
			continue;
		}
	}
	return true;
}
