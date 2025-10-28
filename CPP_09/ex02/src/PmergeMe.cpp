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
		int num = std::atoi(av[i]);
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

bool isNumber(std::string str)
{
	if (str.empty()) return false;
	for (size_t i = 0; i < str.size(); i++)
		if (str[i] < '0' || str[i] > '9')
			return false;
	return true;
}

void PmergeMe::processInputVector(int n, char **av)
{
	for (int i = 0; i < n; i++)
	{
		std::string arg = av[i];
		if (!isNumber(arg))
			throw std::runtime_error("not a valid positive integer.");
		unsigned int num = std::strtoul(arg.c_str(), NULL, 10);
		_vector.push_back(num);
	}
}

void PmergeMe::processInputDeque(int n, char **av)
{
	for (int i = 0; i < n; i++)
	{
		std::string arg = av[i];
		if (!isNumber(arg))
			throw std::runtime_error("not a number.");
		unsigned int num = std::strtoul(arg.c_str(), NULL, 10);
		_deque.push_back(num);
	}
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
	sortMergeInsertVector(_vector);
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
	sortMergeInsertDeque(_deque);
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	return elapsed;
}

void PmergeMe::sortMergeInsertVector(std::vector<unsigned int> &vect)
{
	if (vect.size() <= 1) return ;

	std::vector<unsigned int> right, left;
	std::vector<unsigned int>::iterator it = vect.begin();
	while (it != vect.end())
	{
		unsigned int first = *it;
		++it;
		if (it != vect.end())
		{
			unsigned int second = *it;
			if (first > second)
				std::swap(first, second);
			left.push_back(first);
			right.push_back(second);
			++it;
		}
		else {
			left.push_back(first);
			break ;
		}
	}
	sortMergeInsertVector(right);
	for (std::vector<unsigned int>::iterator lit = left.begin(); lit != left.end(); ++lit)
	{
		std::vector<unsigned int>::iterator pos = std::lower_bound(right.begin(), right.end(), *lit);
		right.insert(pos, *lit);
	}
	vect = right;
}

void PmergeMe::sortMergeInsertDeque(std::deque<unsigned int> &deq)
{
	if (deq.size() <= 1) return ;

	std::deque<unsigned int> right, left;
	std::deque<unsigned int>::iterator it = deq.begin();
	while (it != deq.end())
	{
		unsigned int first = *it;
		++it;
		if (it != deq.end())
		{
			unsigned int second = *it;
			if (first > second)
				std::swap(first, second);
			left.push_back(first);
			right.push_back(second);
			++it;
		}
		else {
			left.push_back(first);
			break ;
		}
	}
	sortMergeInsertDeque(right);
	for (std::deque<unsigned int>::iterator lit = left.begin(); lit != left.end(); ++lit)
	{
		std::deque<unsigned int>::iterator pos = std::lower_bound(right.begin(), right.end(), *lit);
		right.insert(pos, *lit);
	}
	deq = right;
}
