#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int 			_exec_grade;
		static int			_validateGrade(int grade);
	public:
		Form();
		Form(const std::string &name, int sign_g, int exec_g);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string &getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &aBureaucrat);

		class GradeTooHighException: public std::exception{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif