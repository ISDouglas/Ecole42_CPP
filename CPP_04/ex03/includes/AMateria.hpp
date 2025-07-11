#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();                                  // -1-default constructor      
		AMateria(std::string const& type);		     // constructor with parameter
		AMateria(const AMateria& other);             // -2-copy constructor
		AMateria &operator=(const AMateria &other);  // -3-overload of the assignment operator 
		virtual ~AMateria();                         // -4-destructor

		std::string const &getType() const;          //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif