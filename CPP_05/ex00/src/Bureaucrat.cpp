#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name(""), _grade(Lowest)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    if (grade > Lowest)
        throw GradeTooLowException();
    if (grade < Highest)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_name = other._name;
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


void Bureaucrat::increment(const int nb)
{
    if (this->_grade - nb < Highest)
        throw(GradeTooHighException());
    this->_grade -= nb;
}

void Bureaucrat::decrement(const int nb)
{
    if (this->_grade + nb > Lowest)
        throw GradeTooLowException();
    this->_grade += nb;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
    return out;
}
