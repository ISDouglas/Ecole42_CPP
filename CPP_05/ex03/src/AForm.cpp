# include "../includes/Bureaucrat.hpp"
# include "../includes/AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _sign_grade(1), _exec_grade(1)
{}

int	AForm::_validateGrade(int grade)
{
	if (grade > LOWEST)
		throw (GradeTooLowException());
	if (grade < HIGHEST)
		throw (GradeTooHighException());
	return grade;
}

AForm::AForm(const std::string &name, int sign_g, int exec_g): _name(name), _signed(false), _sign_grade(_validateGrade(sign_g)), _exec_grade(_validateGrade(exec_g))
{}

AForm::AForm(const AForm &other): _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}

AForm::~AForm()
{}

std::string AForm::getName() const {	return _name; }
bool AForm::getSigned() const {	return _signed; }
int AForm::getSignGrade() const {	return _sign_grade; }
int AForm::getExecGrade() const {	return _exec_grade; }

void AForm::beSigned(Bureaucrat &aBureaucrat)
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

void AForm::checkExecutability(const Bureaucrat &executor) const
{
	if (!this->_signed)
		throw (FormNotSignedException());
	if (this->_exec_grade < executor.getGrade())
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
    out << "AForm: " << other.getName() 
		<< ", sign grade: " << other.getSignGrade() 
		<< ", execute grade: " << other.getExecGrade() 
		<< ", signed: " << (other.getSigned() ? "Yes" : "No");
    return out;
}
