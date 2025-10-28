#pragma once

# include <vector>
# include <deque>
# include <stdexcept>
# include <iostream>
# include <ctime>
# include <string>

// Containers applied in ex02: std::vector<int>, std::deque<int>
class PmergeMe {
	private:
		std::vector<unsigned int> _input;
		std::deque<unsigned int> _deque;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void processInput(char **av);
		void printResult();
		void countTime();
};
