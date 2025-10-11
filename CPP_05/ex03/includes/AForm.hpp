#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int 			_exec_grade;
		static int			_validateGrade(int grade);
	public:
		AForm();
		AForm(const std::string &name, int sign_g, int exec_g);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &aBureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException: public std::exception{
			public:
				const char *what() const throw() {return "Grade too high";};
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw() {return "Grade too low";};
		};
		class FormNotSignedException: public std::exception {
			public:
				const char *what() const throw() {return "Form not signed";};
		};
	protected:
		void checkExecutability(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#endif
