#include "ScalarConverter.hpp"

bool isInt(std::string &str) {
	bool result = 0;

	size_t i = 0;
	if (i < str.length() && (str[i] == '+' || str[i] == '-'))
		i++;
	if (i < str.length())
		result = 1;
	for (; i < str.length(); i++)
		if (!isdigit(str[i]))
			result = 0;
	return (result);
}

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
		return (false); // neither float nor double

}

int getLiteralType(std::string &str) {

	if (isInt(str))
		return (INT);
	if (str.length() == 1)
		return (CHAR);
	return (isWhichFloat(str));
}

void ScalarConverter::convert(char *str) {
	(void) str;
	std::string input(str);

	int type = getLiteralType(input);
	switch (type) {
		case CHAR:
			std::cout << "str is char\n";
			break;
		case INT:
			std::cout << "str is int\n";
			break;
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
}
