# include "../includes/ScavTrap.hpp"
# include <iostream>

//---------------------  Constructor and Destructor  ---------------------//
ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << getType() << " " << getName() << " is created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << getType() << " " << getName() << " is destroyed." << std::endl;
}

//---------------------  Rewrite  functions ---------------------//
const std::string ScavTrap::getType() const
{
	return "ScavTrap";
}

void ScavTrap::attack(const std::string& target)
{
	int p = getEnergyPoints();
	if (p > 0 && getHitPoints() > 0)
	{
		setEnergyPoints(p--);
		std::cout << getType() << " " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << getType() << " " << getName()
		<< " cannot attack. No energy or hit points left!"
		<< std::endl;
	}
}
//---------------------  Member function  ---------------------//
void ScavTrap::guardGate()
{
	std::cout << getType() << " " << getName()
	<< " is now in Gatekeeper mode." << std::endl;
}

