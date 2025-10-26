#include "../includes/Span.hpp"
#include <ctime>

void stressTest()
{
    std::cout << "\n##******** Stress Test (100,000 elements) ********##" << std::endl;
    Span sp(100000);
    std::vector<int> v(100000);
    std::srand(std::time(0));

    for (size_t i = 0; i < 100000; i++)
        v[i] = std::rand();

    sp.addNumbers(v.begin(), v.end());
    
    std::cout << "           Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "           Longest Span: " << sp.longestSpan() << std::endl;
}

int main()
{
	try {
		std::cout << "##******** test addNumber() and addNumbers()  ********##" << std::endl;
		std::cout << "           Creat Span nbs[5]" << std::endl;
		Span nbs = Span(5);
		std::cout << "           Add -1, nbs: " << std::endl;
		nbs.addNumber(-1);
		std::vector<int> v = nbs.getVector();
		std::cout << "           ";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << "           Add 1, nbs: " << std::endl;
		nbs.addNumber(1);
		v = nbs.getVector();
		std::cout << "           ";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		int arr[] = {3, -9, 345};
		std::vector<int> n(arr, arr + sizeof(arr) / sizeof(int));
		std::cout << "           Add vector {3, -9, 345}, nbs: " << std::endl;
		nbs.addNumbers(n.begin(), n.end());		
		v = nbs.getVector();
		std::cout << "           ";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;	 
		std::cout << "           Add again vector {3, -9, 345}, nbs: " << std::endl;
		nbs.addNumbers(n.begin(), n.end()); 
	}
	catch (const std::runtime_error &e) {
		std::cout << "      Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n##******** test shortest and longest span  ********##" << std::endl;
		std::cout << "           Creat Span nbs[5]" << std::endl;
		Span nbs(5);
		std::cout << "           Add vector {0, 885, 5, -9, -345}, nbs: " << std::endl;
		int arr[] = {0, 885, 5, -9, -345};
		std::vector<int> n(arr, arr + sizeof(arr) / sizeof(int));
		nbs.addNumbers(n.begin(), n.end());
		std::vector<int> v = nbs.getVector();
		std::cout << "           ";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;	
		std::cout << "           Shortest Span: " << nbs.shortestSpan() << std::endl;		
		std::cout << "           Longest Span: " << nbs.longestSpan() << std::endl;
	}
	catch (const std::runtime_error &e) {
		std::cout << "      Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n##******** test shortest and longest span (with < 2 numbers) ********##" << std::endl;
		std::cout << "           Creat Span nbs[5]" << std::endl;
		Span nbs(5);
		std::cout << "           Add -1200000000, nbs: " << std::endl;
		nbs.addNumber(-1200000000);
		std::vector<int> v = nbs.getVector();
		std::cout << "           ";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << "           Shortest Span: " << nbs.shortestSpan() << std::endl;		
		std::cout << "           Longest Span: " << nbs.longestSpan() << std::endl;
	}
	catch (const std::runtime_error &e) {
		std::cout << "      Error: " << e.what() << std::endl;
	}


	try {
		std::cout << "\n##******** test shortest and longest span (with edge) ********##" << std::endl;
		std::cout << "           Creat Span nbs[5]" << std::endl;
		Span nbs(5);
		std::cout << "           Add -1200000000 " << std::endl;
		nbs.addNumber(-1200000000);
		std::cout << "           Add 1100000000, nbs: " << std::endl;
		nbs.addNumber(1100000000);
		std::vector<int> v = nbs.getVector();
		std::cout << "           ";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << "           Shortest Span: " << nbs.shortestSpan() << std::endl;		
		std::cout << "           Longest Span: " << nbs.longestSpan() << std::endl;
	}
	catch (const std::runtime_error &e) {
		std::cout << "      Error: " << e.what() << std::endl;
	}

	stressTest();

	return 0;
}
