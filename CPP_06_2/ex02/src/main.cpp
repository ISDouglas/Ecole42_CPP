#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int n;
	std::srand(std::time(NULL));
	n = std::rand() % 3;
	if (n == 0)
		return (new A);
	else if (n == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...) {}
}

int main()
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}
