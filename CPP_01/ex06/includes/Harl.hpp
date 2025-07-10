#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{	
	public:
		// Constructor
		Harl();
		// Member functions
		void debug();
		void info();
		void warning();
		void error();
		void filter(std::string level);
};

# endif