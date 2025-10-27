# include <iostream>
# include <vector>
#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try {
		if (ac == 1)
			throw std::runtime_error("could not open file.");
		else if (ac > 2)
			throw std::runtime_error("usage: ./btc input.txt.");
		BitcoinExchange btc;
		btc.parseCSV("../data.csv");

		std::ifstream input(av[1]);
		if (!input.is_open())
			throw std::runtime_error("could not open file.");

		std::string line;
		std::getline(input, line);
		while (std::getline(input, line))
			btc.exchangeOutputLine(line);
		input.close();
    }
    catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}   
	return 0;
}

