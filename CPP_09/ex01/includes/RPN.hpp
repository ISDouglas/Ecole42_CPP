#pragma once

# include <stack>
# include <stdexcept>
# include <iostream>
# include <cctype>

// Container applied in ex01: std::stack<int, std::list<int>>
class RPN {
	private:
		std::stack<double> _stack;
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void processExpressionRPN(const std::string &str);
};
