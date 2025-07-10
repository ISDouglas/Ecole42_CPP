#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		std::string getType() const;
	public:
		static const int defaultHitPoints = 100;
		static const int defaultAttackDamage = 30;
		FragTrap();                                // -1-default constructor 
		FragTrap(const std::string& name);         // constructor with parameter
		FragTrap(const FragTrap& aFragTrap);       // -2-copy constructor
		FragTrap &operator=(const FragTrap &other);// -3-overload of the assignment operator 
		~FragTrap();                               // -4-destructor
		void highFivesGuys(void);
};

#endif
