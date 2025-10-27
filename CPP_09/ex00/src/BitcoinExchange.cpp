#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::map<std::string, double> csv)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{}

BitcoinExchange::~BitcoinExchange()
{}


void BitcoinExchange::parseCSV(const std::string fileRates)
{}

double BitcoinExchange::getRate(const std::string &date) const
{}

void BitcoinExchange::exchangeOutputLine(const std::string line)
{}
