#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string _type;		
	public:
		// Constructor
		Weapon(std::string type);
		// Member functions
		const std::string&	getType() const;
		void				setType(std::string newType);
};

# endif