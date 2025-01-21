#pragma once

# include <string>
# include <iostream>

class Harl{

	public:

		Harl();

		void complain(std::string level);

	private:

		void debug();
		void info();
		void warning();
		void error();

		typedef void (Harl::*HarlComplaint)();
		HarlComplaint complaints[4];
};