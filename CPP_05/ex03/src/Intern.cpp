#include "../includes/Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

// static helpers
static AForm* createShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

// make form
AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(* funcs[3])(const std::string &) = {
        &createShrubberyForm, &createRobotomyForm, &createPresidentialForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return funcs[i](formTarget);
        }
    }
    std::cout << "Intern: ❌ form name \"" << formName << "\" not recognized!" << std::endl;
    return NULL;
}
