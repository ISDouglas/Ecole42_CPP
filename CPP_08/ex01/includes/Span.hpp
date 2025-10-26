#pragma once
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits>
# include <iostream>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _v;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);         
        ~Span();

        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator bbegin, std::vector<int>::iterator end);
        long long shortestSpan();
        long long longestSpan();

        std::vector<int> getVector() const;
};
