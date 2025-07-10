#include "../includes/DiamondTrap.hpp"
#include <iostream>

//---------------------  Constructors and Destructor  ---------------------//
DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), FragTrap(),
							ScavTrap(), _name("Default")
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	setHitPoints(FragTrap::defaultHitPoints);
	setEnergyPoints(ScavTrap::defaultEnergyPoints);
	setAttackDamage(FragTrap::defaultAttackDamage);
	std::cout << this->getType() << " " << _name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"),
												FragTrap(), ScavTrap(), _name(name)
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	setHitPoints(FragTrap::defaultHitPoints);
	setEnergyPoints(ScavTrap::defaultEnergyPoints);
	setAttackDamage(FragTrap::defaultAttackDamage);
	std::cout << this->getType() << " " << _name << " is created." << std::endl;
	std::cout << " " << std::endl;
	std::cout << this->getType() << " " << _name << " Hit points: "
			<< this->getHitPoints() << std::endl;
	std::cout << this->getType() << " " << _name << " Energy points: "
		<< this->getEnergyPoints() << std::endl;
	std::cout << this->getType() << " " << _name << " Attack damage: "
			<< this->getAttackDamage() << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap& aDiamondTrap)
					: ClapTrap(aDiamondTrap.ClapTrap::getName()),
					FragTrap(), ScavTrap(), _name(aDiamondTrap._name)
{
	setHitPoints(aDiamondTrap.getHitPoints());
	setEnergyPoints(aDiamondTrap.getEnergyPoints());
	setAttackDamage(aDiamondTrap.getAttackDamage());
	std::cout << this->getType() << " " << _name << " is copied." << std::endl;
	std::cout << " " << std::endl;
	std::cout << this->getType() << " " << _name << " Hit points: "
			<< this->getHitPoints() << std::endl;
	std::cout << this->getType() << " " << _name << " Energy points: "
		<< this->getEnergyPoints() << std::endl;
	std::cout << this->getType() << " " << _name << " Attack damage: "
			<< this->getAttackDamage() << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	std::string na = this->_name;
	if (this != &other)
	{
		ClapTrap::setName(other.ClapTrap::getName());
		this->_name = other._name;
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	std::cout << this->getType() << " " << this->_name << " is assigned to: " << na << std::endl;
	std::cout << " " << std::endl;
	std::cout << this->getType() << " " << _name << " Hit points: "
			<< this->getHitPoints() << std::endl;
	std::cout << this->getType() << " " << _name << " Energy points: "
		<< this->getEnergyPoints() << std::endl;
	std::cout << this->getType() << " " << _name << " Attack damage: "
			<< this->getAttackDamage() << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->getType() << " " << this->_name << " is destroyed." << std::endl;
}

//---------------------  Rewrite  functions ---------------------//
std::string DiamondTrap::getType() const
{
	return "DiamondTrap";
}

void DiamondTrap::attack(const std::string& target)
{
	std::cout << "DiamondTrap attack() inherited from ScavTrap: " << ScavTrap::getName() << std::endl;
	ScavTrap::attack(target);
}
//---------------------  Member functions  ---------------------//
void DiamondTrap::whoAmI() const
{
	std::cout << "My DiamondTrap name: " << this->_name << std::endl;
	std::cout << "My ClapTrap name: " << ClapTrap::getName() << std::endl;	
}
