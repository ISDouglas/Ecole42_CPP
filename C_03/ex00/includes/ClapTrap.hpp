#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap {
	private:
		std::string _name;
		int _hitPoints = 10;
		int _energyPoints = 10;
		int _attackDamage = 0;
	public:
		ClapTrap(const std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
