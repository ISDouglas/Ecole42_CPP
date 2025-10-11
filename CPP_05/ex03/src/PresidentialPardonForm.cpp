#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("presidential pardon", 25, 5), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("presidential pardon", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other): AForm(other), _target(other._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    checkExecutability(executor);
    std::cout << "🕊 " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;       
}
