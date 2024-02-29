#include "ScalarConverter.hpp"

int main (int argc, char **argv) {
	(void)argv;
	if (argc != 2)
		std::cout << "invalid number of arguments\n";
	std::cout <<"wow\n" ;
	std::string str("13e13");
	try {
		std::stof(str);
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
}
