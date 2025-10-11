#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery creation", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("shrubbery creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other): AForm(other), _target(other._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecutability(executor);
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "❌ Failed to create shrubbery file for target: " << this->_target << std::endl;
        return ;
    }
	file <<
	"          🌳🌳🌳          \n"
	"       🌳🌳🌳🌳🌳🌳       \n"
	"     🌳🌳🌳🌳🌳🌳🌳🌳     \n"
	"           |||||          \n"
	"           |||||          \n"
	"           |||||          \n"
	"--------------------------\n";
	file.close();
	std::cout << "✅ " << this->_target << "_shrubbery created successfully!" << std::endl;
}
