#include "../includes/MutantStack.hpp"
# include <iostream>
# include <list>

int main()
{
	std::cout << "// ---------------------- Test using MutantStack ----------------------" << std::endl; 
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nPrinting MutantStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::stack<int> tmp(s);
	std::cout << "\nPrinting std::stack s, copied from MutantStack:" << std::endl;
	while (!tmp.empty())
	{
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}

	std::cout << "\n// ---------------------- Test using std::list ----------------------" << std::endl;	
	std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    l.pop_back();
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);

    std::cout << "Printing std::list, simulating MutantStack behavior:" << std::endl;
    for (std::list<int>::iterator lit = l.begin(); lit != l.end(); ++lit)
    {
        std::cout << *lit << std::endl;
    }
	return 0;
}
