#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

class Span
{
private:
    unsigned int _N;
    std::vector<int> _span;
    class   full;
    class   not_enought_num;
public:
    Span(unsigned int n);
    Span();
    Span(const Span &cpy);
    ~Span();
    Span &operator=(Span &cpy);
    //// MEMBER FUCTIONS ////
    void    addNumber(int num);
    unsigned int     shortestSpan();
    unsigned int     longestSpan();
    void             fill(std::vector<int>::iterator start, std::vector<int>::iterator end);
};

class Span::not_enought_num : std::exception
{
    virtual const char *what() const throw()
    {
        return "Less than 2 numbers in the vector!!";
    }
};

class Span::full : std::exception
{
    virtual const char *what() const throw()
    {
        return "Span Full";
    }
};