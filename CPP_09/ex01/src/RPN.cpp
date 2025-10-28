#include "../includes/RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &other): _stack(other._stack)
{}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_stack = other._stack;
	return *this;
}

RPN::~RPN()
{}


void RPN::processExpressionRPN(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (c == ' ') continue ;
		if (isdigit(c))
			_stack.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: less than 2 numbers for calculating.");
			double b = _stack.top(); _stack.pop();
			double a = _stack.top(); _stack.pop();
			switch (c) {
				case '+': _stack.push(a + b); break;
				case '-': _stack.push(a - b); break;
				case '*': _stack.push(a * b); break;
				case '/': _stack.push(a / b); break;
			}

		}
		else {
			throw std::runtime_error("Error: non-legal char detected.");
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid input.");
	std::cout << _stack.top() << std::endl;
}
