#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form {
	private:
		std::string	_name;
		bool		_signed;
		int			_sign_grade;
		int 		_exec_grade;
	public:
		Form();
		Form(const std::string name, bool sign, int sign_g, int exec_g);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &aBureaucrat);

		class GradeTooHighException: public std::exception{
			public:
				const char *what() const throw() {return "Grade too high!";};
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw() {return "Grade too low!";};
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif