#include "../includes/Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat c("Bob", 2);
        std::cout << c << std::endl;
        c.increment(1);
        c.increment(1);

        Bureaucrat d("David", 145);
        std::cout << d << std::endl;
        d.decrement(7);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat a("one", 151);
        Bureaucrat b("two", -2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
