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
		std::vector<unsigned int> _vector;
		std::deque<unsigned int> _deque;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void processMergeInsert(int n, char **av);

		void processInputVector(int n, char **av);
		void processInputDeque(int n, char **av);
		
		void sortMergeInsertVector();
		void sortMergeInsertDeque();
		
		double countTimeVectorInput(int n, char **av);
		double countTimeVectorSort();
		double countTimeDequeInput(int n, char **av);
		double countTimeDequeSort();
};
