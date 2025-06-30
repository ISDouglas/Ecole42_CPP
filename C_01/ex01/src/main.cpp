#include "../includes/Zombie.hpp"
#include <iostream>

int main()
{
	int	N = 5;
	Zombie* horde = zombieHorde(N, "deads");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
