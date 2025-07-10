#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "../includes/Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;
	public:
		// Constructor
		HumanA(std::string name, Weapon& weapon);
		// Member function
		void    attack() const;
};

#endif
