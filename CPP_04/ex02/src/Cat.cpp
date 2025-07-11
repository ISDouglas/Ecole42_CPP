#include "../includes/Cat.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
Cat::Cat(): Animal("Cat"), _brain(new Brain)
{
	std::cout << "Default Cat(type: Cat) created." << std::endl;
}

Cat::Cat(const std::string& typeName): Animal(typeName), _brain(new Brain)
{
	std::cout << "Cat(type: " << typeName << ") created." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat(type: " << this->_type << ") copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		Brain* new_brain = new Brain(*other._brain); //Use deep copy, not shallow copy
		delete _brain;
		_brain = new_brain;
	}
	std::cout << "Cat(type: " << this->_type << ") assigned." << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat(type: " << this->_type << ") destroyed." << std::endl;
}

//---------------------  Member functions  ---------------------//
void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}
