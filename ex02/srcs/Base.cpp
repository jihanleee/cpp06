#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {

}

Base * generate(void) {
	std::ifstream rand;
	char c;
	rand.open ("/dev/random");
	rand.get(c);
	rand.close();
	c = c % 3 * ((c > 0) ? 1 : -1);
	switch (c) {
		case 0:
			return (new A);
		break;
		case 1:
			return (new B);
		break;
		case 2:
			return (new C);
		break;
	}
	return (NULL);
}

void identify(Base* p) {

	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p) {
	try{
		(void)dynamic_cast<A&>(p);
			std::cout << "A\n";
	}
	catch(std::exception &e){
		//std::cout << "not a\n";
	}

	try{
		(void)dynamic_cast<B&>(p);
			std::cout << "B\n";
	}
	catch(std::exception &e){
		//std::cout << "not b\n";
	}

	try{
		(void)dynamic_cast<C&>(p);
			std::cout << "C\n";
	}
	catch(std::exception &e){
		//std::cout << "not c\n";
	}
}
