#include "../includes/Bureaucrat.hpp"
# include "../includes/Form.hpp"

int main()
{
	std::cout << "\n-----   -----ex00: Bureaucrat-----   -----" << std::endl;
	try {
		Bureaucrat c("Bob", 2);
		std::cout << c << std::endl;
		c.increment();
		std::cout << c << std::endl;
		c.increment();
		std::cout << c << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try {
		Bureaucrat d("David", 150);
		std::cout << d << std::endl;
		d.decrement();
		std::cout << d << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Bureaucrat a("one", 151);		
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat b("two", -2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n-----   -----ex01: Form-----   -----" << std::endl;
	try
	{
		Bureaucrat b("Alice(Bureaucrat)", 72);
		std::cout << b << std::endl;
		Form a("Hugo(Form)", 70, 80);
		std::cout << a << std::endl;
		Form c("Kid(Form)", 80, 80);
		std::cout << c << std::endl;
		std::cout << std::endl;

		b.signForm(a);
		std::cout << a << std::endl;
		std::cout << std::endl;

		b.signForm(c);
		std::cout << c << std::endl;
		std::cout << std::endl;

		c.beSigned(b);
		a.beSigned(b);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n-----   -----ex02: AForm-----   -----" << std::endl;
}
