#include "../includes/Zombie.hpp"
#include <iostream>

int main()
{
	std::cout << "+++Creating Zombie on heap:" << std::endl;
	Zombie* heapZombie = newZombie("heapzombie");
	heapZombie->announce();
	std::cout << "---Using /delete/" << std::endl;  
	delete heapZombie;
	std::cout << std::endl;
	std::cout << "+++Creating Zombie on stack:" << std::endl;
	randomChump("stackZombie");
	return 0;
}
