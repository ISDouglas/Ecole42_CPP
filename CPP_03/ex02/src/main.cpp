# include "../includes/FragTrap.hpp"
# include <iostream>

int main()
{
	FragTrap st("Ferena");
	st.attack("the enemy");
	st.takeDamage(30);
	st.beRepaired(20);
	st.takeDamage(130);
	st.takeDamage(30);
	st.highFivesGuys();
	return 0;
}
