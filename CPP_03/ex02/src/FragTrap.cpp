# include "../includes/FragTrap.hpp"
# include <iostream>

//---------------------  Constructors and Destructor  ---------------------//
FragTrap::FragTrap(): ClapTrap("Default_ScavTrap")
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << getType() << " " << getName() << " is created." << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << getType() << " " << getName() << " is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& aFragTrap): ClapTrap(aFragTrap.getName())
{
	this->setHitPoints(aFragTrap.getHitPoints());
	this->setEnergyPoints(aFragTrap.getEnergyPoints());
	this->setAttackDamage(aFragTrap.getAttackDamage());
	std::cout << getType() << " " << getName() << " is created." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	std::cout << getType() << " " << getName() << " is created." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << getType() << " " << getName() << " is destroyed." << std::endl;
}

//---------------------  Rewrite  getType() ---------------------//
std::string FragTrap::getType() const
{
	return "FragTrap";
}
//---------------------  Member function  ---------------------//
void FragTrap::highFivesGuys(void)
{
	std::cout << getType() << " " << getName()
	<< " requests high fives! ✋ Positive vibes only!" << std::endl;
}

