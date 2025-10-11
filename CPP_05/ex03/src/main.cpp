#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

void printTreeFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "❌ Could not open file: " << filename << std::endl;
        return;
    }

    std::cout << "\n🌳 Content of " << filename << ":\n";
    std::cout << "-----------------------------------\n";
    std::string line;
    while (std::getline(file, line))
        std::cout << line << std::endl;
    std::cout << "-----------------------------------\n";
    file.close();
}

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

		std::cout << " The -From- class becomes an abstract class -AForm- , test ex01 id omitted here. " << std::endl;


	std::cout << "\n-----   -----ex02: AForm-----   -----" << std::endl;
    std::srand(std::time(NULL)); // Random seed for RobotomyRequestForm
    try
    {
        std::cout << "=== Bureaucrat creation ===" << std::endl;
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 140);
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        std::cout << "\n=== Form creation ===" << std::endl;
        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("Bender");
        PresidentialPardonForm f3("Arthur");
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
		
        std::cout << "\n=== Signing and executing with low-grade bureaucrat (Bob) ===" << std::endl;
        b2.signForm(f1);
        b2.executeForm(f1); // should fail, Bob too low to execute
        std::cout << std::endl;
        std::cout << "\n=== Signing and executing with high-grade bureaucrat (Alice) ===" << std::endl;
        // ShrubberyCreationForm
        b1.signForm(f1);
        b1.executeForm(f1);
        // Print generated file
        printTreeFile("home_shrubbery");
        // RobotomyRequestForm
        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        b1.signForm(f2);
        for (int i = 0; i < 5; i++) // test multiple times for 50% success rate
        {
            b1.executeForm(f2);
        }
        // PresidentialPardonForm
        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        b1.signForm(f3);
        b1.executeForm(f3);
        std::cout << "\n=== End of tests ===" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "❌ Exception caught: " << e.what() << std::endl;
    }

	std::cout << "\n-----   -----ex03: Intern-----   -----" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		Bureaucrat bob("Bob", 40);
		std::cout << bob << std::endl;
		bob.signForm(*rrf);
		bob.executeForm(*rrf);
		delete rrf;
	}

	std::cout << std::endl;
	someRandomIntern.makeForm("coffee request", "Bob"); // Unknown form
		
	return 0;
}
