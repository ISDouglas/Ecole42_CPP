#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		std::string getType() const;
	public:
		static const int defaultEnergyPoints = 50;
		ScavTrap();                                 // -1-default constructor
		ScavTrap(const std::string& name);          // constructor with parameter
		ScavTrap(const ScavTrap& aScavTrap);        // -2-copy constructor
		ScavTrap &operator=(const ScavTrap& other); // -3-overload of the assignment operator
		~ScavTrap();                                // -4-destructor
		void attack(const std::string& target);
		void guardGate();
};

#endif
