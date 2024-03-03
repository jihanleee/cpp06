#include "ScalarConverter.hpp"
#include <cctype>


/*checks if the input complies with the grammar of the string for atof conversion.*/
int isWhichFloat(std::string &str) {
	size_t i = 0;

	/* inf or nan cases*/
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (FLOAT);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (DOUBLE);
	/*mantissa part*/
	if (i < str.length() && (str[i] == '+' || str[i] == '-'))
		i++;
	if (i < str.length() && str[i] == '.') {
		i++;
		if (i < str.length() && std::isdigit(str[i]))
			for (;i < str.length() && std::isdigit(str[i]); i++); //skips consecutive digits
		else
			return (false);
	}
	else {
		if (i < str.length() && std::isdigit(str[i]))
			for (;i < str.length() && std::isdigit(str[i]); i++); //skips consecutive digits
		else
			return (false);
		if (i < str.length() && str[i] == '.') {
			i++;
			if (i < str.length() && std::isdigit(str[i]))
				for (;i < str.length() && std::isdigit(str[i]); i++); //skips consecutive digits
		}
	}

	/*exponent part*/
	if (i < str.length() && (str[i] == 'e' || str[i] == 'E')) { // when exponent exists
		i++;
		if (i < str.length() && (str[i] == '+' || str[i] == '-')) //sign of the exponent
			i++;
		if (i < str.length() && std::isdigit(str[i]))
			for (;i < str.length() && std::isdigit(str[i]); i++); //skips consecutive digits
		else
			return (false);
	}
	if (i == str.length()) // when successfully reached eof
		return (DOUBLE);
	else if (i < str.length() && str[i] == 'f')
		return (FLOAT);
	else
		return (false);

}

static int getVariableType(std::string &str) {
	bool isInt;

	isInt = 1;
	for (size_t i = 0; i < str.length(); i++)
		if (!isdigit(str[i]))
			isInt = 0;
	if (isInt)
		return (INT);
	if (str.length() == 3 && str.at(0) == '\'' && str.at(2) == '\'' && isprint(str.at(1)))
		return (CHAR);
	return (-1);
}

void ScalarConverter::convert(char *str) {
	(void) str;
/* 	std::string input(str);

	type = getVariableType(input); */
}
