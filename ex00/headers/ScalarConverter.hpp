#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <string>

class ScalarConverter {
	public:
		static void convert(char *str);
};

bool isFloat(std::string &str);

#endif