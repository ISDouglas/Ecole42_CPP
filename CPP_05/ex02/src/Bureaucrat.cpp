#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat():_name("default"), _grade(LOWEST)
{}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
    if (grade > LOWEST)
        throw GradeTooLowException();
    if (grade < HIGHEST)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}


void Bureaucrat::increment()
{
    if (this->_grade - 1 < HIGHEST)
        throw(GradeTooHighException());
    this->_grade--;
}

void Bureaucrat::decrement()
{
    if (this->_grade + 1 > LOWEST)
        throw GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(AForm &aForm)
{
    try {
        aForm.beSigned(*this);
        std::cout << this->_name << " signed " << aForm.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " couldn't sign " <<
        aForm.getName() << " because " << e.what() << "." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
    return out;
}
