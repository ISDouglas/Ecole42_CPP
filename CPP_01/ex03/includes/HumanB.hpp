#pragma once
#include "../includes/Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;
	public:
        // Constructor
		HumanB(std::string name);
        // Member function
        void    setWeapon(Weapon& weapon);
		void    attack() const;
};
