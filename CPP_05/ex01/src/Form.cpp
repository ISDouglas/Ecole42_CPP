# include "../includes/Bureaucrat.hpp"
# include "../includes/Form.hpp"

Form::Form(): _name(""), _signed(false), _sign_grade(1), _exec_grade(1)
{}

Form::Form(const std::string name, bool sign, int sign_g, int exec_g): _name(name), _signed(sign), _sign_grade(sign_g), _exec_grade(exec_g)
{}

Form::Form(const Form &other): _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_signed = other._signed;
		this->_sign_grade = other._sign_grade;
		this->_exec_grade = other._exec_grade;
	}
	return *this;
}

Form::~Form()
{}

std::string Form::getName() const
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
	
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
    out << "form: " << other.getName() << ", sign grade: " << other.getSignGrade() <<
     ", execute grade: " << other.getExecGrade() << ", signed: " << other.getSigned();
    return out;
}