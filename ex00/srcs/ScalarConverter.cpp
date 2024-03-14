#include "ScalarConverter.hpp"

bool isIntOverflow(std::string &str) {
	long longVar;

	errno = 0;
	longVar = strtol(str.c_str(), NULL, 10);

	if (longVar < INT_MIN || longVar > INT_MAX || errno == ERANGE) {
		errno = 0;
		return (1);
	}
	return (0);
}

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
	else if (i < str.length() && str[i] == 'f' && i == str.length() - 1) // when the last char is 'f'
		return (FLOAT);
	else
		return (false); // neither float nor double

}

bool isFloatOverflow(std::string &str) {
	errno = 0;
	strtof(str.c_str(), NULL);

	if (errno == ERANGE) {
		errno = 0;
		return (1);
	}
	return (0);
}

bool isDoubleOverflow(std::string &str) {

	errno = 0;
	strtod(str.c_str(), NULL);

	if (errno == ERANGE) {
		errno = 0;
		return (1);
	}
	return (0);
}

int getLiteralType(std::string &str) {
	if (isInt(str) && !isIntOverflow(str))
		return (INT);
	if (str.length() == 3 && str.at(0) == '\'' && str.at(2) == '\'' && isprint(str.at(1)))
		return (CHAR);
	int precisionType;

	precisionType = isWhichFloat(str);
	if (precisionType == FLOAT && !isFloatOverflow(str)) {
		return (FLOAT);
	}
	else if (precisionType == DOUBLE && !isDoubleOverflow(str)){
		return (DOUBLE);
	}
	return (false);
}

template <typename T> void convertVars(T value) {

	if (value < -128 || value > 127 || isnan(value))
		std::cout << "char: impossible\n";
	else if (std::isprint((char)value))
		std::cout << "char: " << "'" << char(value) << "'" << std::endl;
	else
		std::cout << "char: is not printable\n";
	if (value < INT_MIN || value > INT_MAX || isnan(value))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << int(value) << std::endl;
	std::cout << "float: " << float(value) << "f" << std::endl;
	std::cout << "double: " << double(value) << std::endl;
}

void ScalarConverter::convert(char *str) {
	(void) str;
	std::string input(str);

	int type = getLiteralType(input);
	switch (type) {
		case CHAR:
			convertVars(str[1]);
			break;
		case INT:
			convertVars(strtol(str, NULL, 10));
			break;
		case FLOAT:
			convertVars(strtof(str, NULL));
			break;
		case DOUBLE:
			convertVars(strtod(str, NULL));
			break;
		case false:
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			break;
	}
}
