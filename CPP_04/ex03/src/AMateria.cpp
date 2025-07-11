#include "../includes/AMateria.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
AMateria::AMateria(): _type("anAMateria")
{
	std::cout << "Default AMateria (type: anAMateria) created." << std::endl;
}

AMateria::AMateria(const std::string& type): _type(type)
{
	std::cout << "AMateria (type: " << type << ") created." << std::endl;
}

AMateria::AMateria(const AMateria& other): _type(other._type)
{
	std::cout << "AMateria (type: " << this->_type << ") copied." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "AMateria (type: " << this->_type << ") assigned." << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria (type: " << this->_type << ") destroyed." << std::endl;
}

//---------------------  Member functions  ---------------------//
std::string const &AMateria::getType() const
{
	return this->_type;
}

AMateria* AMateria::clone() const
{
	std::cout << "no clone for pure virtual AMateria" << std::endl;
}

void AMateria::use(ICharacter& target)
{
	
}