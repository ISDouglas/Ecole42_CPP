# include "../includes/FragTrap.hpp"
# include <iostream>

//---------------------  Constructor and Destructor  ---------------------//
FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << getType() << " " << getName() << " is created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << getType() << " " << getName() << " is destroyed." << std::endl;
}

//---------------------  Rewrite  getType() ---------------------//
const std::string FragTrap::getType() const
{
	return "FragTrap";
}
//---------------------  Member function  ---------------------//
void FragTrap::highFivesGuys(void)
{
	std::cout << getType() << getName()
	<< " requests high fives! ✋ Positive vibes only!" << std::endl;
}

