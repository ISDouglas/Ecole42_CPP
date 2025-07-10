# include "../includes/ScavTrap.hpp"
# include <iostream>

//---------------------  Constructors and Destructor  ---------------------//
ScavTrap::ScavTrap()//: ClapTrap("Default_ScavTrap")
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << getType() << " " << getName() << " is created." << std::endl;
}
ScavTrap::ScavTrap(const std::string& name)//: ClapTrap(name)
{
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << getType() << " " << getName() << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& aScavTrap)//: ClapTrap(aScavTrap.getName())
{
	this->setName(aScavTrap.getName());
	this->setHitPoints(aScavTrap.getHitPoints());
	this->setEnergyPoints(aScavTrap.getEnergyPoints());
	this->setAttackDamage(aScavTrap.getAttackDamage());
	std::cout << getType() << " " << getName() << " is copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	std::cout << getType() << " " << getName() << " is created." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << getType() << " " << getName() << " is destroyed." << std::endl;
}

//---------------------  Rewrite  functions ---------------------//
std::string ScavTrap::getType() const
{
	return "ScavTrap";
}

void ScavTrap::attack(const std::string& target)
{
	int p = this->getEnergyPoints();
	if (p > 0 && this->getHitPoints() > 0)
	{
		this->setEnergyPoints(p - 1);
		std::cout << this->getType() << " " << this->getName() << " attacks " << target
		          << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << this->getType() << " " << this->getName()
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

