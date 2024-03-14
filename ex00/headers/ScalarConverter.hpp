#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <climits>
# include <cerrno>
# include <cmath>
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4

class ScalarConverter {
	public:
		static void convert(char *str);
};

int isWhichFloat(std::string &str);
int getLiteralType(std::string &str);
template <typename T> void convertVars(T value);
#endif