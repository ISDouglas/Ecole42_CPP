#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice: public AMateria {

	public:
		Ice();                                  // -1-default constructor
		Ice(const std::string& type);       	// constructor with parameter
		Ice(const Ice& other);                  // -2-copy constructor
		Ice &operator=(const Ice &other);       // -3-overload of the assignment operator 
		~Ice();                                 // -4-destructor

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif