#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <stdexcept>
# include <fstream>
# include <iostream>
# include <sstream>
# include <limits>

//map<string, double>   
class BitcoinExchange {
    private:
        std::map<std::string, double> _rates;
    public:
        BitcoinExchange();
        BitcoinExchange(std::map<std::string, double> csv);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void parseCSV(const std::string fileRates);
        double getRate(const std::string &date) const;
        std::string removeSpace(std::string str);
        int validDateValue(const std::string d, const std::string v);
        void exchangeOutputLine(const std::string line);
};

#endif
