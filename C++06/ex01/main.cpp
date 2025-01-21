#include "Serializer.hpp"

int main(){
	Data* data = new Data;
	data->num = 1;
	uintptr_t ptr = Serializer::serialize(data);
	std::cout << data << "\n" << ptr << "\n" << Serializer::deserialize(ptr) << std::endl;
	delete data;
	return 0;
}