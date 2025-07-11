#include "../includes/Animal.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
Animal::Animal(): _type("anAnimal")
{
	std::cout << "Default Animal(type: anAnimal) created." << std::endl;
}

Animal::Animal(const std::string& typeName): _type(typeName)
{
	std::cout << "Animal(type: " << typeName << ") created." << std::endl;
}

Animal::Animal(const Animal& other): _type(other._type)
{
	std::cout << "Animal(type: " << this->_type << ") copied." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Animal(type: " << this->_type << ") assigned." << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal(type: " << this->_type << ") destroyed." << std::endl;
}

//---------------------  Member functions  ---------------------//
std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "What Does the Fox Say? -Ring-ding-ding-ding-dingeringeding!" << std::endl;
}
