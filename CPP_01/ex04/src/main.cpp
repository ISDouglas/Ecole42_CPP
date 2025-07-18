#include <iostream>
#include <fstream>

inline void	openerror(std::string file)
{
	std::cerr << "Error on opening the file " << file << std::endl;
	exit(1);
}

static void	replace(std::ifstream& in, const std::string& sr, const std::string& re, std::ofstream& out)
{
	std::string line;
	while (std::getline(in, line))
	{
		std::string	newLine;
		std::size_t pos = 0;
		std::size_t start = 0;
		while ((pos = line.find(sr, start)) != std::string::npos)
		{
			newLine += line.substr(start, pos - start);
			newLine += re;
			start = pos + sr.length();
		}
		newLine += line.substr(start);
		out << newLine << "\n";
	}
}

int main(int ac, char   *av[])
{
	if (ac != 4)
	{
		std::cout << "Replace exemple: ./replace Makefile RESET  ++++" << std::endl;
		return 1;
	}
	std::ifstream infile(av[1]);
	if (!infile.is_open())
		openerror(std::string(av[1]));
	std::string filename = std::string(av[1]) + ".replace";
	std::ofstream outfile(filename);
	if (!outfile.is_open())
	{
		infile.close();
		openerror(filename);
	}
	replace(infile, std::string(av[2]), std::string(av[3]), outfile);
	infile.close();
	outfile.close();
	return 0;
}
