#include "../includes/ScalarConverter.hpp"

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

/* void ScalarConverter::_printConvert(double d)
{
	if (d < 0 || d > 127 || std::isnan(d))
		std::cout << "char: impossible" << std::endl;	
	else if (d < 32 || d == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	
	if (d < std::numeric_limits<int>::min() ||
		d > std::numeric_limits<int>::max() ||
		d == std::isnan(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f"<< std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;	
} */

static void checkPrecision(double d)
{
    float f = static_cast<float>(d);

    // for float 
    if (std::fabs(d) > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else if (static_cast<double>(f) != d) {
        std::cout << "float: precision loss: " << std::fixed << std::setprecision(1)
                  << f << "f" << std::endl;
	}
    else
	{
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << f << "f" << std::endl;
	}
    // for double 
	if (std::fabs(d) > static_cast<double>(1ULL << 53)) {
        std::cout << "double: precision loss: " << std::fixed << std::setprecision(1)
                  << d << std::endl;
	}
    else {
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << d << std::endl;
	}
}

void ScalarConverter::_printConvert(double d)
{
	if (d < 0 || d > 127 || std::isnan(d))
		std::cout << "char: impossible" << std::endl;	
	else if (d < 32 || d == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	
	if (d < std::numeric_limits<int>::min() ||
		d > std::numeric_limits<int>::max() ||
		d == std::isnan(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	checkPrecision(d);
} 

void ScalarConverter::_convertToDouble(const std::string &value, int type)
{
	double d = 0.0;

	switch (type)
	{
		case T_CHAR:
			d = static_cast<double>(value[0]);
			break ;
		case T_INT:
			d = static_cast<double>(std::atoi(value.c_str()));
			break ;
		case T_FLOAT:
			d = static_cast<double>(std::strtof(value.c_str(), NULL));
			break ;
		case T_DOUBLE:
			d = std::strtod(value.c_str(), NULL);
			break ;
		default:
			break ;
	}
	if (errno == ERANGE || d == HUGE_VAL || d == -HUGE_VAL)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	_printConvert(d);
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
