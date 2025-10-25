#pragma once
# include <vector>

class Span {
    private:
        unsigned int _N;
        std::vector<int> v;
    public:
        void addNumber();
        unsigned int shortestSpan();
        unsigned int longestSpan();

};
