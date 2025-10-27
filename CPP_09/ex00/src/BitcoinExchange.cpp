#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::map<std::string, double> csv): _rates(csv)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _rates(other._rates)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}


void BitcoinExchange::parseCSV(const std::string fileRates)
{
	std::ifstream file(fileRates.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open file.");
	
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, rateStr;
		if (std::getline(ss , date , ',') && std::getline(ss , rateStr))
		{
			double rate = std::atof(rateStr.c_str());
			_rates[date] = rate;
		}
	}
	file.close();
}

double BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _rates.find(date);
	if (it != _rates.end())
		return it->second;
	it = _rates.upper_bound(date);
	if (it == _rates.begin())
	{
		std::cout << "Error: no earlier date available for " << date << std::endl;
		return -1.0;
	}
	--it;
	return it->second;
}

std::string BitcoinExchange::_removeSpace(std::string str)
{
	std::string value;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
			value += str[i];
	}
	return value;
}

bool BitcoinExchange::_isValidDate(std::string date)
{
	int year, month, day;
	std::istringstream yss(date.substr(0, 4));
	std::istringstream mss(date.substr(5, 2));
	std::istringstream dss(date.substr(8, 2));
	if (!(yss >> year) || !(mss >> month) || !(dss >> day)) return false;
	if (month < 1 || month > 12) return false;
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1]) return false;
	return true;
}

bool BitcoinExchange::_isValidValue(std::string value)
{
	char *endptr = NULL;
	double num = std::strtod(value.c_str(), &endptr);

	if (*endptr != '\0')
	{
		std::cout << "Error: bad input => " << value << std::endl;
		return false;
	}
	if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	bool hasDot = (value.find('.') != std::string::npos);
	if (!hasDot)
	{
		if (num > std::numeric_limits<int>::max())
		{
			std::cout << "Error: too large a number." << std::endl;
			return false;
		}
	}
	else
	{
		if (num > std::numeric_limits<double>::max())
		{
			std::cout << "Error: too large a number." << std::endl;
			return false;
		}
	}
	return true;
}

int BitcoinExchange::_validDateValue(const std::string date, const std::string value)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-' 
		|| !_isValidDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 0;
	}
	if (!_isValidValue(value))
		return 0;
	return 1;
}

void BitcoinExchange::exchangeOutputLine(const std::string line)
{
	std::istringstream ss(line);
	std::string date, value;
	if (std::getline(ss, date, '|') && std::getline(ss, value))
	{
		date = _removeSpace(date);
		value = _removeSpace(value);
		if (_validDateValue(date, value))
		{
			double val = std::atof(value.c_str());
			double r = getRate(date);
			if (r == -1.0)
				return ;
			double result = val * r;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}	
	}
}
