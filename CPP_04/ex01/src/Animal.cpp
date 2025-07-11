#include "../includes/Animal.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
Animal::Animal(): type("anAnimal")
{
	std::cout << "Default Animal(type: anAnimal) created." << std::endl;
}

Animal::Animal(const std::string& typeName): type(typeName)
{
	std::cout << "Animal(type: " << typeName << ") created." << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
	std::cout << "Animal(type: " << this->type << ") copied." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal(type: " << this->type << ") assigned." << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal(type: " << this->type << ") destroyed." << std::endl;
}

//---------------------  Member functions  ---------------------//
std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "What Does the Fox Say? -Ring-ding-ding-ding-dingeringeding!" << std::endl;
}
