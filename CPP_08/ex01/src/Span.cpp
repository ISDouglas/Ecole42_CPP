#include "../includes/Span.hpp"

Span::Span()
{}

Span::Span(unsigned int N): _N(N)
{}

Span::Span(const Span &other): _N(other._N), _v(other._v)
{}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_v = other._v;
	}
	return *this;
}
         
Span::~Span()
{}
      
void Span::addNumber(int n)
{
	if (this->_N > this->_v.size())
		this->_v.push_back(n);
	else
		throw std::runtime_error("Span is already full, can not add anymore");
}	

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _N)
		throw std::runtime_error("Cannot add numbers: Span is full");
	for (std::vector<int>::iterator it = begin; it != end; it++)
		addNumber(*it);
}

long long Span::shortestSpan()
{
	if (this->_v.size() < 2)
		throw std::runtime_error("No shortest span can be built with fewer than two numbers");

	std::vector<int> sorted = this->_v;
	std::sort(sorted.begin(), sorted.end());
	long long min = static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]);
	for (size_t i = 2; i < sorted.size(); i++)
	{
		long long diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

long long Span::longestSpan()
{
	if (this->_v.size() < 2)
		throw std::runtime_error("No longest span can be built with fewer than two numbers");

	int min = *std::min_element(_v.begin(), _v.end());
	int max = *std::max_element(_v.begin(), _v.end());

	return static_cast<long long>(max) - static_cast<long long>(min);
}
std::vector<int> Span::getVector() const
{
	return this->_v;
}
