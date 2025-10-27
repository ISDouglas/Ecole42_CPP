#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <stdexcept>
# include <fstream>
# include <iostream>
# include <sstream>
# include <limits>
# include <cstdlib>

// Container applied in ex00: map<string, double>   
class BitcoinExchange {
	private:
		std::map<std::string, double> _rates;
		bool _isValidDate(std::string date);
		bool _isValidValue(std::string value);
		std::string _removeSpace(std::string str);
		int _validDateValue(const std::string date, const std::string value);
	public:
		BitcoinExchange();
		BitcoinExchange(std::map<std::string, double> csv);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void parseCSV(const std::string fileRates);
		double getRate(const std::string &date) const;
		void exchangeOutputLine(const std::string line);
};

#endif
