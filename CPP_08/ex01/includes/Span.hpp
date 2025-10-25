#pragma once
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _v;
    public:
        Span() = delete;
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);         
        ~Span();

        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator bbegin, std::vector<int>::iterator end);
        long long shortestSpan();
        long long longestSpan();

};
