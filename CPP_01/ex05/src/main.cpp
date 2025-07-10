#include <iostream>
#include "../includes/Harl.hpp"

int	main(int ac, char	*av[])
{
	Harl harl;
	if (ac != 2)
	{
		std::cout << "Harl exemple: ./harl WARNING" << std::endl;
		return 1;
	}
	harl.complain(std::string(av[1]));
	return 0;
}
