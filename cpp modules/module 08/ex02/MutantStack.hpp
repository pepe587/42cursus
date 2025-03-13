#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
    std::stack<T> _stack;

public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    MutantStack(){};
    ~MutantStack(){};

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

};
