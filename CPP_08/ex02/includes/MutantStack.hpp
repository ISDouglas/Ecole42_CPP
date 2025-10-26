#pragma once
# include <stdexcept>
# include <algorithm>
# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		MutantStack(): std::stack<T, Container>() {}
		MutantStack(const MutantStack<T, Container> &other): std::stack<T, Container>(other){}
		MutantStack<T, Container> &operator=(const MutantStack<T, Container> &other)
		{
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return *this;
		}        
		~MutantStack(){}

		iterator begin() {return this->c.begin(); }
		iterator end() {return this->c.end(); }
		const_iterator begin() const {return this->c.begin(); }
		const_iterator end() const {return this->c.end(); }
};
