# include "../includes/Bureaucrat.hpp"
# include "../includes/Form.hpp"

Form::Form(): _name("default"), _signed(false), _sign_grade(1), _exec_grade(1)
{}

int	Form::_validateGrade(int grade)
{
	if (grade > LOWEST)
		throw (GradeTooLowException());
	if (grade < HIGHEST)
		throw (GradeTooHighException());
	return grade;
}

Form::Form(const std::string &name, int sign_g, int exec_g): _name(name), _signed(false), _sign_grade(_validateGrade(sign_g)), _exec_grade(_validateGrade(exec_g))
{}

Form::Form(const Form &other): _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	return *this;
}

Form::~Form()
{}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _sign_grade;
}

int Form::getExecGrade() const
{
	return _exec_grade;
}

void Form::beSigned(Bureaucrat &aBureaucrat)
{
	if (this->_signed == true)
	{
		std::cout << this->_name << " is already signed." << std::endl; 
		return ;
	}
	if (aBureaucrat.getGrade() <= this->_sign_grade)
	{		
		this->_signed = true;
		std::cout << this->_name << " was just signed by " 
			<< aBureaucrat.getName() << "." << std::endl; 
	}
	else
		throw (GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw() {return "Grade too high";}
const char *Form::GradeTooLowException::what() const throw() {return "Grade too low";}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
    out << "form: " << other.getName() << ", sign grade: " << other.getSignGrade() <<
     ", execute grade: " << other.getExecGrade() << ", signed: " << (other.getSigned() ? "Yes" : "No");
    return out;
}
