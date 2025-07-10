# include "../includes/ClapTrap.hpp"
# include <iostream>

//--------------------- Constructors and Destructor ---------------------//
ClapTrap::ClapTrap()
{
	this->_name = "Default_ClapTrap";
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
	std::cout << getType() << " " << this->_name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
	this->_name = name;
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
	std::cout << getType() << " " << this->_name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& aClapTrap)
{
	this->_name = aClapTrap.getName();
	setHitPoints(aClapTrap.getHitPoints());
	setEnergyPoints(aClapTrap.getEnergyPoints());
	setAttackDamage(aClapTrap.getAttackDamage());
	std::cout << getType() << " " << this->_name << " is copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	std::cout << getType() << " " << this->_name << " is created." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << getType() << " " << this->_name << " is destroyed." << std::endl;
}

//---------------------    Setters and Getters    ---------------------//
void ClapTrap::setName(const std::string name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(int p)
{
	if (p < 0)
		p = 0;
	this->_hitPoints = p;
}
void ClapTrap::setEnergyPoints(int p)
{
	if (p < 0)
		p = 0;
	this->_energyPoints = p;
}

void ClapTrap::setAttackDamage(int p)
{
	if (p < 0)
		p = 0;
	this->_attackDamage = p;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

std::string ClapTrap::getType() const
{
	return "ClapTrap";
}

int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

//---------------------  Member functions  ---------------------//
void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << getType() << " " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << getType() << " " << _name
		<< " cannot attack. No energy or hit points left!"
		<< std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (_hitPoints > amount)
			_hitPoints -= amount;
		else
			_hitPoints = 0;
		std::cout << getType() << " " << _name << " took " << amount
		          << " points of damage. Current HP: " << _hitPoints << std::endl;
	}
	else
	{
		std::cout << getType() << " "  << _name << " is already down!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << getType() << " " << _name << " regained " << amount
		<< " points. Current HP: " << _hitPoints << std::endl;
	}
}
