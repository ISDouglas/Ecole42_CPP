#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>

class MateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif