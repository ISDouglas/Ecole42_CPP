#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
		void _clearInventory();
		void _copyInventory(const Character& other);

	public:
		Character();                                  // -1-default constructor
		Character(const std::string& name);       	  // constructor with parameter
		Character(const Character& other);            // -2-copy constructor
		Character &operator=(const Character &other); // -3-overload of the assignment operator 
		virtual ~Character();      

		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif