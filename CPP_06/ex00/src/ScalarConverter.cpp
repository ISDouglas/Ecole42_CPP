#include "../includes/ScalarConverter.hpp"
#include <iostream>

enum LiteralType {T_INT, T_CHAR, T_FLOAT, T_DOUBLE, T_PSEUDO, T_INVALID};

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

int ScalarConverter::_getType(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf" ||
		str == "-inf" || str == "+inf" || str == "nan")
		return T_PSEUDO;
	if (str.size() == 1 && !std::isdigit(str[0]))
		return T_CHAR;
	
	bool hasDot = false;
	bool hasF = false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.size(); i++)
	{
		if (str[i] == '.' && !hasDot)
			hasDot = true;
		else if (str[i] == 'f' && !hasF)
			hasF = true;
		else if (!std::isdigit(str[i]))
			return T_INVALID;
	}
	if (hasDot && hasF)
		return T_FLOAT;
	else if (hasDot)
		return T_DOUBLE;
	else
		return T_INT;
}

void ScalarConverter::_printPseudo(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;	
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::_printDouble(double value)
{}

void ScalarConverter::_convertToDouble(const std::string &value, int type)
{
	double d = 0.0;

}

void ScalarConverter::convert(const std::string value)
{
    
	int type = _getType(value);
	if (type == T_INVALID)
	{
		std::cout << "Invalid literal." << std::endl;
		return ;
	}
	if (type == T_PSEUDO)
	{
		_printPseudo(value);
		return ;
	}
	_convertToDouble(value, type);
}


/* 
#include "../includes/ScalarConverter.hpp"

enum LiteralType { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_PSEUDO, TYPE_INVALID };

// ---------------- 构造函数禁用 ---------------- //
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

// ---------------- 辅助函数实现 ---------------- //

bool ScalarConverter::isPseudo(const std::string &s)
{
	return (s == "nan" || s == "nanf" ||
			s == "+inf" || s == "+inff" ||
			s == "-inf" || s == "-inff");
}

int ScalarConverter::detectType(const std::string &value)
{
	if (isPseudo(value))
		return (TYPE_PSEUDO);
	if (value.length() == 1 && !std::isdigit(value[0]))
		return (TYPE_CHAR);

	bool hasDot = false;
	bool hasF = false;
	size_t i = 0;

	if (value[i] == '+' || value[i] == '-')
		i++;

	for (; i < value.size(); ++i)
	{
		if (value[i] == '.' && !hasDot)
			hasDot = true;
		else if (value[i] == 'f' && i == value.size() - 1)
			hasF = true;
		else if (!std::isdigit(value[i]))
			return (TYPE_INVALID);
	}

	if (hasDot && hasF)
		return (TYPE_FLOAT);
	else if (hasDot)
		return (TYPE_DOUBLE);
	return (TYPE_INT);
}

void ScalarConverter::printPseudo(const std::string &value)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (value == "nan" || value == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (value == "+inf" || value == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (value == "-inf" || value == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::displayConversions(double value)
{
	// char
	if (value < 0 || value > 127 || std::isnan(value))
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || value == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	// int
	if (value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max() ||
		std::isnan(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// float
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertToAll(const std::string &value, int type)
{
	double d = 0.0;

	switch (type)
	{
		case TYPE_CHAR:
			d = static_cast<double>(value[0]);
			break;
		case TYPE_INT:
			d = static_cast<double>(std::atoi(value.c_str()));
			break;
		case TYPE_FLOAT:
			d = static_cast<double>(std::strtof(value.c_str(), NULL));
			break;
		case TYPE_DOUBLE:
			d = std::strtod(value.c_str(), NULL);
			break;
		default:
			break;
	}
	displayConversions(d);
}

// ---------------- 主接口 ---------------- //

void ScalarConverter::convert(const std::string &value)
{
	int type = detectType(value);
	if (type == TYPE_INVALID)
	{
		std::cout << "Invalid literal" << std::endl;
		return;
	}
	if (type == TYPE_PSEUDO)
	{
		printPseudo(value);
		return;
	}
	convertToAll(value, type);
}

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
follow your code, can we have the same result like:
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
?
the switch() {case ...}may print all the results of 4 types? anwer me in chiense */
