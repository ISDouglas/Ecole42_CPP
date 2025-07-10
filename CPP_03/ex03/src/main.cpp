#include "../includes/DiamondTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Creating DiamondTrap ===" << std::endl;
	DiamondTrap dTrap("Dio");

	std::cout << "\n=== Checking inherited stats ===" << std::endl;	
	std::cout << " === Hit points needs to be: 100 as in FragTrap ===" << std::endl;
	std::cout << " === Energy points needs to be: 50 as in ScavTrap ===" << std::endl;
	std::cout << " === Attack damage needs to be: 30 as in FragTrap ===" << std::endl;

	std::cout << "\n=== Checking whoAmI() ===" << std::endl;
	dTrap.whoAmI(); // Should print "My name is Dio, my ClapTrap name is Dio_clap_name"

	std::cout << "\n=== Testing attack() ===" << std::endl;
	dTrap.attack("Enemy");

	std::cout << "\n=== Testing copy constructor ===" << std::endl;
	DiamondTrap newTrap(dTrap);

	std::cout << "\n=== Testing overload of the assignment operator ===" << std::endl;
	DiamondTrap otherTrap;
	std::cout << std::endl;
	otherTrap = newTrap;

	std::cout << "\n=== Using up energy ===" << std::endl;
	for (int i = 0; i < 51; ++i) {
		dTrap.attack("Dummy");
	}
	std::cout << "" << std::endl;
	std::cout << "\n=== whoAmI() after exhausting energy ===" << std::endl;
	dTrap.whoAmI();

	std::cout << "\n=== Creating another DiamondTrap ===" << std::endl;
	DiamondTrap another("Jotaro");
	another.whoAmI();
	another.attack("Dio");
	std::cout << "" << std::endl;
	return 0;
}
