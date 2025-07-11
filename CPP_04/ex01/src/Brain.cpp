#include "../includes/Brain.hpp"
#include <iostream>
#include <string>

//---------------------  Constructors and Destructor  ---------------------//
Brain::Brain()
{
	std::cout << "Default Brain created." << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain copied." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain assigned." << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed." << std::endl;
}

//---------------------  Member functions  ---------------------//
void Brain::setIdea(int index, const std::string idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
	else
		std::cout << "Idea assign failed, wrong index." << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return "Idea get failed, wrong index.";
}
