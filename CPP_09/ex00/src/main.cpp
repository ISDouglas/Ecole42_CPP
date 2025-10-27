#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try {
		if (ac == 1)
			throw std::runtime_error("could not open file.");
		else if (ac > 2)
			throw std::runtime_error("usage: ./btc input.txt.");
		BitcoinExchange btc;
		btc.parseCSV("data.csv");

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

/* 
example of input.txt

date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
2019-02-29 | 10
2020-02-29 | 5
2020-02-29 | 0.5
2021-05-12 | 10
2021-05-12 | 200
2008-12-31 | 100
2012-04-31 | 7
2012-06-15 | 0
2012-06-15 | abc
2012-06-15 | 2147483646
2012-07-01|5
2012-07-02 | 3.14
2012-07-03  | 2

*/