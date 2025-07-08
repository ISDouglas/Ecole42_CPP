# include "../includes/ScavTrap.hpp"
# include <iostream>

int main()
{
	ScavTrap st("Serena");
	st.attack("the enemy");
	st.takeDamage(30);
	st.beRepaired(20);
	st.takeDamage(130);
	st.takeDamage(30);
	st.guardGate();
	return 0;
}
