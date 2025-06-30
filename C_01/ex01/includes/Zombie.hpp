#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string _name;
		
	public:
		// Constructor and Destructor
		Zombie();
		Zombie(std::string name);
		~Zombie();
		// Member functions
		void	announce(void);
		void	setName(std::string name);	
};

Zombie* zombieHorde(int N, std::string name);

# endif