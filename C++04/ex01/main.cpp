#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	/* const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	... */
	int i = 10;
	Animal *animals[i];
	for (int j = 0; j < i; j++){
		std::cout << j << std::endl;
		if (j < i / 2)
			animals[j] = new Dog();
		else
			animals[j] = new Cat();
	}
	for (int j = 0; j < i; j++){
		std::cout << j << std::endl;
		delete animals[j];
	}
	return 0;
}
