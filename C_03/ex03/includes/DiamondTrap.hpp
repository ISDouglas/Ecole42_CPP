#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// --------------   Multiple inheritance and virtual inheritance ----------------- //
class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string _name;
	protected:
		std::string getType() const;
	public:
		DiamondTrap();                                   // -1-default constructor 
		DiamondTrap(const std::string& name);            // constructor with parameter
		DiamondTrap(const DiamondTrap& aDiamondTrap);    // -2-copy constructor
		DiamondTrap &operator=(const DiamondTrap &other);// -3-overload of the assignment operator 
		~DiamondTrap();                                  // -4-destructor

		void attack(const std::string& target);
		void whoAmI() const;
};

#endif
