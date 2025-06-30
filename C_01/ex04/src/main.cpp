#include <iostream>
#include <fstream>

inline void	openerror(std::string file)
{
	std::cerr << "Error on opening the file " << file << std::endl;
	exit(1);
}

static void	replace(std::ifstream& in, std::string& sr, std::string& re, std::ofstream& out)
{
	std::string line;
	while (std::getline(in, line))
	{

	}

}

/* static void replace(std::ifstream& infile, const std::string& s1, const std::string& s2, const std::string& filename)
{
	std::ofstream outfile(filename + ".replace");
	if (!outfile.is_open())
		openerror((filename + ".replace").c_str());

	std::string line;
	while (std::getline(infile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());   // 删掉原字符串
			line.insert(pos, s2);           // 插入新字符串
			pos += s2.length();             // 移动位置，避免死循环
		}
		outfile << line << std::endl;
	}
	outfile.close();
} */

int main(int ac, char   *av[])
{
	if (ac != 4)
	{
		std::cout << "Raplace exemple: ./replace Makefile RESET  ++++" << std::endl;
		return 1;
	}
	std::ifstream infile(av[1]);
	if (!infile.is_open())
		openerror(std::string(av[1]));
	std::string filename = std::string(av[1]) + ".replace";
	std::ofstream outfile(filename);
	if (!outfile.is_open())
		openerror(filename);
	replace(infile, av[2], av[3]);
	infile.close();
	return 0;
}
