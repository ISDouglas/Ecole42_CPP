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
		void setName(const std::string name);
		void setHitPoints(int p);
		void setEnergyPoints(int p);
		void setAttackDamage(int p);

		std::string getName() const;
		std::string getType() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
	public:
		ClapTrap();                                // -1-default constructor 
		ClapTrap(const std::string& name);         // constructor with parameter
		ClapTrap(const ClapTrap& aClapTrap);       // -2-copy constructor
		ClapTrap &operator=(const ClapTrap& other);// -3-overload of the assignment operator 
		~ClapTrap();                               // -4-destructor
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
