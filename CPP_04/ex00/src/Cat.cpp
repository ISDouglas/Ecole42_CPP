#include "../includes/Cat.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
Cat::Cat(): Animal("Cat")
{
	std::cout << "Default Cat(type: Cat) created." << std::endl;
}

Cat::Cat(const std::string& typeName): Animal(typeName)
{
	std::cout << "Cat(type: " << typeName << ") created." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "Cat(type: " << this->_type << ") copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Cat(type: " << this->_type << ") assigned." << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat(type: " << this->_type << ") destroyed." << std::endl;
}

//---------------------  Member function  ---------------------//
void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
