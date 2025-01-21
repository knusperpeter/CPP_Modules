# include <fstream>
# include <string>
# include <iostream>

int main(int ac, char **av){
	if (ac != 4)
		return (std::cerr << "Usage: " << av[0] << " <filename> <string1> <string2>" << std::endl, 1);
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::ifstream file(filename.c_str());
	std::string line;
	std::string new_filename = filename + ".replace";
	std::ofstream new_file(new_filename.c_str());

	if (!file.is_open() || !new_file.is_open())
		return (std::cerr << "Could not open the file" << std::endl, 1);

	while (getline(file, line)){
		size_t pos;
		while ((pos = line.find(s1)) != std::string::npos){
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		new_file << line;
		if (file.eof())
			break;
		new_file << std::endl;
	}
	return 0;
}