#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main () {
	Base* pobj;
	pobj = generate();
	identify(pobj);
	identify(*pobj);
	delete pobj;

	Base* pA = new A;
	Base* pB = new B;
	Base* pC = new C;

	std::cout << "identify pointer A :";
	identify(pA);
	std::cout << "identify reference A :";
	identify(*pA);

	std::cout << "identify pointer B :";
	identify(pB);
	std::cout << "identify reference B :";
	identify(*pB);

	std::cout << "identify pointer C :";
	identify(pC);
	std::cout << "identify reference C :";
	identify(*pC);

	delete (pA);
	delete (pB);
	delete (pC);

	return 0;
}
