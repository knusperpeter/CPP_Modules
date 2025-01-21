#include <iostream>
#include <string>
int main(int ac, char **av){
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < ac; i++){
			std::string what = av[i];
			for (std::string::iterator it = what.begin(); it != what.end(); ++it){
				*it = std::toupper(*it);
			}
			std::cout << what;
		}
		std::cout << std::endl;
	}
	return 0;
}
