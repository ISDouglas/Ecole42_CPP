# include "../includes/ClapTrap.hpp"
# include <iostream>

ClapTrap::ClapTrap(const std::string name)
{
	this->_name = name;
	std::cout << "ClapTrap " << _name << " is created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name
		<< " cannot attack. No energy or hit points left!"
		<< std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " took " << amount
		          << " points of damage. Current HP: " << _hitPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " is already down!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " regained " << amount
		<< " points." << std::endl;
	}
}
