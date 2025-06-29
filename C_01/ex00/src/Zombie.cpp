#include "../includes/Zombie.hpp"
#include <iostream>

void	Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << _name << " is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}
