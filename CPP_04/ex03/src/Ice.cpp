#include "../includes/Ice.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
Ice::Ice(): AMateria("ice")
{
	std::cout << "Default Ice (type: ice) created." << std::endl;
}

Ice::Ice(const std::string& type): AMateria(type)
{
	std::cout << "Ice (type: " << type << ") created." << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other)
{
	std::cout << "Ice (type: " << this->_type << ") copied." << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Ice (type: " << this->_type << ") assigned." << std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice (type: " << this->_type << ") destroyed." << std::endl;
}

//---------------------  Member functions  ---------------------//
Ice* Ice::clone() const
{
	Ice new(*this);
	return *new;
}

void Ice::use(ICharacter& target)  //
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}