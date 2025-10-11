#include "../includes/Bureaucrat.hpp"

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
}
