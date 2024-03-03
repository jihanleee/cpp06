#include "ScalarConverter.hpp"

int main (int argc, char **argv) {
	if (argc != 2)
		std::cout << "invalid number of arguments\n";
	std::cout <<"wow\n" ;
	std::string str(argv[1]);
	if (isFloat(str))
		std::cout << "str is float string\n";
	else
		std::cout << "str is not convertible\n";
	return (0);
}
