#include "../includes/Aminal.hpp"
#include <iostream>

//---------------------  Constructors and Destructor  ---------------------//
Aminal::Aminal()
{
	std::cout << "Default Animal(type: anAnimal) created." << std::endl;
}

Aminal::Aminal(const std::string& typeName)
{
	this->_type = typeName;
	std::cout << "Animal(type: " << typeName << ") created." << std::endl;
}

Aminal::Animal(const Animal& other)
{
	this->_type = other._type;
	std::cout << "Animal(type: " << this->_type << ") copied." << std::endl;
}

Aminal::Animal &operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Animal(type: " << this->_type << ") assigned." << std::endl;
	return *this;
}

Aminal::~Aminal()
{
	std::cout << "Animal(type: " << this->_type << ") destroyed." << std::endl;
}

//---------------------  Member function  ---------------------//
void Aminal::makeSound()
{
	std::cout << "What Does the Fox Say? -Ring-ding-ding-ding-dingeringeding!" << std::endl;
}
