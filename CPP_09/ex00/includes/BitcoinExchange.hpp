#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <stdexcept>

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
        void exchangeOutputLine(const std::string line);
};

#endif
