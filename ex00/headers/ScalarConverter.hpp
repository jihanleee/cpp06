#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <string>
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4

class ScalarConverter {
	public:
		static void convert(char *str);
};

int isWhichFloat(std::string &str);

#endif