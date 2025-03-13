#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class exc : std::exception
{
    public:
    const char *what() const throw()
    {
        return "Number not found";
    }
};

template <typename T>
int *easyfind(T a, int num)
{
    typename T::iterator iter;

    iter = std::find(a.begin(), a.end(), num);
    if (iter == a.end())
        throw exc();
    return (&(*iter));
}