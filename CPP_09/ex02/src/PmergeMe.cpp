#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other): _vector(other._vector), _deque(other._deque)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::processMergeInsert(int n, char **av)
{
	double timeVectorDataInput = countTimeVectorInput(n, av);

	// print Before:
	_vector.clear();
	std::cout << "Before: ";
	for (int i = 0; i < n; i++) {
		int num = std::atoi(av[i+1]);
		_vector.push_back(num);
		std::cout << num << " ";
	}
	std::cout << std::endl;

	double timeVectorSort = countTimeVectorSort();
	double timeVectorTotal = timeVectorDataInput + timeVectorSort;

	double timeDequeDataInput = countTimeDequeInput(n, av);
	double timeDequeSort = countTimeDequeSort();
	double timeDequeTotal = timeDequeDataInput + timeDequeSort;

	// print After:
	std::cout << "After:  ";
	for (size_t i = 0; i < _deque.size(); i++)
		std::cout << _deque[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << n << " elements with std::vector : " 
			<< timeVectorTotal << " us" << std::endl;
	std::cout << "Time to process a range of " << n << " elements with std::deque : " 
			<< timeDequeTotal << " us" << std::endl;
}

void PmergeMe::processInputVector(int n, char **av)
{

}

void PmergeMe::processInputDeque(int n, char **av)
{

}

double PmergeMe::countTimeVectorInput(int n, char **av)
{
	clock_t start = clock();
	processInputVector(n, av);
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	return elapsed;
}

double PmergeMe::countTimeVectorSort()
{
	clock_t start = clock();
	sortMergeInsertVector();
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	return elapsed;	
}

double PmergeMe::countTimeDequeInput(int n, char **av)
{
	clock_t start = clock();
	processInputDeque(n, av);
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	return elapsed;
}

double PmergeMe::countTimeDequeSort()
{
	clock_t start = clock();
	sortMergeInsertDeque();
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	return elapsed;
}

void PmergeMe::sortMergeInsertVector()
{}

void PmergeMe::sortMergeInsertDeque()
{}
