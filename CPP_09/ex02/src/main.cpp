#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cerr << "Error : Usage: ./PmergeMe 3 5 9 7 4" << std::endl;
		return 1;
	}
	try {
		PmergeMe nbs;
		av++;
		nbs.processInput(av);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;       
	}
    return 0;
}
