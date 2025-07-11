#include "../includes/Dog.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
Dog::Dog(): Animal("Dog")
{
	std::cout << "Default Dog(type: Dog) created." << std::endl;
}

Dog::Dog(const std::string& typeName): Animal(typeName)
{
	std::cout << "Dog(type: " << typeName << ") created." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "Dog(type: " << this->type << ") copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Dog(type: " << this->type << ") assigned." << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog(type: " << this->type << ") destroyed." << std::endl;
}

//---------------------  Member function  ---------------------//
void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
