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

}

void identify(Base& p) {

}
