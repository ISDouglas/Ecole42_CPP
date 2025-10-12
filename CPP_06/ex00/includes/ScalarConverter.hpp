#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();	
		
		//inner tool functions
		static int _getType(const std::string &str);
		static void _printPseudo(const std::string &str);
		static void _printDouble(double value);
		static void _convertToDouble(const std::string &value, int type);
	public:
		static void convert(const std::string value);
	};

#endif
