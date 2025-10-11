#include "../includes/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target): AForm(name, 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other): AForm(other), _target(other._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkExecutability(executor);
    std::cout << "🤖 Brrrrr.....#$$^^%&*##@#%. " << std::endl;
    if (std::rand() % 2)  // == 0
    	std::cout << "✅ " << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "❌ Robotomy failed for " << this->_target << "!" << std::endl;       
}


