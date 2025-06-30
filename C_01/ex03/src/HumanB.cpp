#include "../includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name):_name(name), _weapon(nullptr) {}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (!_weapon)
		std::cout << _name << "(HumanB) has no weapon to attack." << std::endl;
	else
		std::cout << _name << " attacks with their  " << _weapon->getType() << std::endl;
}
