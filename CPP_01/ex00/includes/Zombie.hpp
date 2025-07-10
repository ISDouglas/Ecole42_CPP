#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string _name;
		
	public:
		// Constructor and Destructor
		Zombie(std::string name);
		~Zombie();
		// Member functions
		void	announce(void);		
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string	name);

# endif