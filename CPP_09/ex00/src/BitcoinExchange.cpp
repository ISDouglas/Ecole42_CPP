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

std::string BitcoinExchange::removeSpace(std::string str)
{
	std::string value;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
			value += str[i];
	}
	return value;
}

int BitcoinExchange::validDateValue(const std::string d, const std::string v)
{
	//2012-01-11 | -1:         Error: not a positive number.
	//2001-42-42:              Error: bad input => 2001-42-42
	//2012-01-11 | 2147483648: Error: too large a number.
	std::string date = removeSpace(d);
	std::string value = removeSpace(v);

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return 0;
	//how to valid if it is a real exist date, including no 2019-02-29 or no 2019-22-28 etc.
	// ====== 提取年/月/日 ======
	int year, month, day;
	std::istringstream yss(date.substr(0, 4));
	std::istringstream mss(date.substr(5, 2));
	std::istringstream dss(date.substr(8, 2));
	if (!(yss >> year) || !(mss >> month) || !(dss >> day))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 0;
	}

	// ====== 验证月份和日期范围 ======
	if (month < 1 || month > 12)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 0;
	}

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 0;
	}


	// how to valid if value is an integer, it is a valid integer; like 2147483648 is invalid.
/* 	int haspoint = 0;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (date[i] < '0' || date[i] > '9')
		{
			if (i == 0 || i == value.size() - 1) return 0;
			if (date[i] == '.' && !haspoint)
				haspoint = 1;
			else
				return 0;
		}
	}
	if (!haspoint) */

	// ====== 检查数值是否有效 ======
	char *endptr = NULL;
	double num = std::strtod(value.c_str(), &endptr);

	// 检查是否为纯数字或有效小数
	if (*endptr != '\0')
	{
		std::cout << "Error: bad input => " << value << std::endl;
		return 0;
	}

	if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 0;
	}

	// 判断是整数还是小数
	bool hasDot = (value.find('.') != std::string::npos);

	if (!hasDot)
	{
		// 没有小数点 => 按整数检查范围
		if (num > std::numeric_limits<int>::max())
		{
			std::cout << "Error: too large a number." << std::endl;
			return 0;
		}
	}
	else
	{
		// 有小数点 => 按 double 检查范围
		if (num > std::numeric_limits<double>::max())
		{
			std::cout << "Error: too large a number." << std::endl;
			return 0;
		}
	}
	return 1;
}

void BitcoinExchange::exchangeOutputLine(const std::string line)
{
	std::istringstream ss(line);
	std::string date, value;
	if (std::getline(ss, date, '|') && std::getline(ss, value))
	{
		if (validDateValue(date, value))
		{
			double val = std::atof(value.c_str());
			double r = getRate(date);
			if (r == -1.0)
				return ;
			double result = val * r;
			//2011-01-03 => 3 = 0.9
			std::cout << date << " => " << value << " = " << result << std::endl;
		}	
	}
}
