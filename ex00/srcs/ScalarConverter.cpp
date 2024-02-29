#include "ScalarConverter.hpp"
#include <cctype>
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

static int getVariableType(std::string &str) {
	bool isInt;

	isInt = 1;
	for (size_t i = 0; i < str.length(); i++)
		if (!isdigit(str.at(i)))
			isInt = 0;
	if (isInt)
		return (INT);
	if (str.length() && str.at(0) == '\'' && str.at(2) == '\'' && isprint(str.at(1)))
		return (CHAR);

}

static void ScalarConverter::convert(char *str) {
	std::string input(str);
	int	type;

	type = getVariableType(input);
}
