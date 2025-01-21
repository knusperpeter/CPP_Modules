#pragma once

# include <string>
# include <iostream>
# include <stdint.h>

struct Data{
	int	num;
};

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer(){}
	Serializer(const Serializer& other){(void)other;}
	~Serializer(){}
	Serializer& operator=(const Serializer& other){(void)other; return *this;}
};