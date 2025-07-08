# include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap rabbit("Rabbit");
	std::string carrot = "Carrot";

	rabbit.attack(carrot);
	rabbit.takeDamage(5);
	rabbit.beRepaired(4);
	rabbit.attack("enemy");
	rabbit.takeDamage(10);
	rabbit.beRepaired(1);
}
