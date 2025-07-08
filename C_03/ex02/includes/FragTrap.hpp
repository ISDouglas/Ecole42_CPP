#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	protected:
		const std::string getType() const;
	public:
		FragTrap(const std::string name);
		~FragTrap();
		void highFivesGuys(void);
};

#endif
/* 
		ClapTrap();                                // -1-default constructor 
		ClapTrap(const std::string name);          // constructor with parameter
		ClapTrap(const ClapTrap& aClapTrap);       // -2-copy constructor
		ClapTrap &operator=(const ClapTrap &other);// -3-overload of the assignment operator 
		~ClapTrap();                               // -4-destructor
 */