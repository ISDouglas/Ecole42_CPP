#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap {
	private:    // Make all member variables private
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	protected:  // Using most complete encapsulation (setter and getter)
		void setHitPoints(int p);
		void setEnergyPoints(int p);
		void setAttackDamage(int p);

		const std::string getName() const;
		const std::string getType() const;
		const int getHitPoints() const;
		const int getEnergyPoints() const;
		const int getAttackDamage() const;
	public:
		ClapTrap();                                // -1-default constructor 
		ClapTrap(const std::string name);          // constructor with parameter
		ClapTrap(const ClapTrap& aClapTrap);       // -2-copy constructor
		ClapTrap &operator=(const ClapTrap &other);// -3-overload of the assignment operator 
		~ClapTrap();                               // -4-destructor
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
