#include "../includes/Dog.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
Dog::Dog(): Animal("Dog"), _brain(new Brain())
{
	std::cout << "Default Dog(type: Dog) created." << std::endl;
}

Dog::Dog(const std::string& typeName): Animal(typeName), _brain(new Brain)
{
	std::cout << "Dog(type: " << typeName << ") created." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog(type: " << this->type << ") copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
		Brain* new_brain = new Brain(*other._brain); //Use deep copy, not shallow copy
		delete _brain;
		_brain = new_brain;
	}
	std::cout << "Dog(type: " << this->type << ") assigned." << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog(type: " << this->type << ") destroyed." << std::endl;
}

//---------------------  Member functions  ---------------------//
void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}
