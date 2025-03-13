#include "Span.hpp"

Span::Span() : _N(10000){}

Span::Span(unsigned int n) : _N(n){}

Span::Span(const Span &cpy)
{
    this->_N = cpy._N;
    this->_span = cpy._span;
}

Span &Span::operator=(Span &cpy)
{
    if (this != &cpy)
    {
        this->_N = cpy._N;
        this->_span = cpy._span;
    }
    return *this;
}

Span::~Span()
{
}

void    Span::addNumber(int num)
{
    if (_span.size() == this->_N)
        throw full();
    _span.push_back(num);
}
unsigned int    Span::shortestSpan()
{
    int size = _span.size();
    int diff = INT_MAX;
    if (size < 2)
        throw not_enought_num();
    for (int i = 0; i < size - 1; i++)
    {
        if (abs(_span[i] - _span[i + 1]) < diff)
            diff = abs(_span[i] - _span[i + 1]);
    }
    return diff;
}
unsigned int    Span::longestSpan()
{
    int size = _span.size();
    int diff = 0;
    if (size < 2)
        throw not_enought_num();
    for (int i = 0; i < size - 1; i++)
    {
        if (abs(_span[i] - _span[i + 1]) > diff)
            diff = abs(_span[i] - _span[i + 1]);
    }
    return diff;
}
void    Span::fill(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    for (; start != end; start++)
    {
        if (_span.size() == this->_N)
            throw full();
        addNumber(*start);
    }
        
}