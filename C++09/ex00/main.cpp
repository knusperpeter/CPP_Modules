#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: can not open file" << std::endl;
        return 1;
    }
	std::map<int, float> exchange_rate;
	if (!parse_data(&exchange_rate))
		return 1;
	convert_input(&exchange_rate, av[1]);

	
	(void)av;
    return 0;
}