#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define Lowest 150
# define Highest 1

class Bureaucrat {
    private:
        std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void increment(const int nb);
        void decrement(const int nb);        
    class GradeTooHighException: public std::exception {
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