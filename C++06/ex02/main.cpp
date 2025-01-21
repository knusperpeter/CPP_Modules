#include "Base.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main(){
	srand(time(NULL));
	for (int i = 0; i < 5; ++i) {
		Base* obj = generate();
		std::cout << "Object " << i + 1 << ": ";
		identify(obj);
		std::cout << "Using reference: ";
		identify(*obj);
		delete obj;
		std::cout << std::endl;
	}
	return 0;
}

Base * generate(void){
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	
	case 2:
		return new C();
	default :
		return NULL;
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	(void)p;
}

void identify(Base& p){
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch(std::exception&) {
		try{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch(std::exception&){
			try{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch(std::exception&){
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}