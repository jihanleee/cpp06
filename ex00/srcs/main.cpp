#include "ScalarConverter.hpp"

int main (int argc, char **argv) {
	if (argc != 2)
		std::cout << "invalid number of arguments\n";
	std::cout <<"wow\n" ;
	std::string str(argv[1]);
	switch (isWhichFloat(str)) {
		case FLOAT:
			std::cout << "str is float\n";
			break;
		case DOUBLE:
			std::cout << "str is double\n";
			break;
		case false:
			std::cout << "str is not convertible\n";
			break;
	}
	return (0);
}
