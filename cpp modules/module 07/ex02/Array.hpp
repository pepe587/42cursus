#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>

template <typename T>
class Array
{
private:
    T *array;
    unsigned int _size;
public:
    Array()
    {
        array = new T[64];
        _size = 0;
        std::memset(array, 0, sizeof(T) * _size);
    }
    Array(unsigned int n)
    {
        array = new T[n];
        _size = n;
        std::memset(array, 0, sizeof(T) * _size);

    }
    Array(Array &cpy)
    {
        this->array = new T[cpy.size()];
        _size = cpy.size();
        for (size_t i = 0; i < this->_size; i++)
        {
            this->array[i] = cpy.array[i];
        }
    }
    ~Array()
    {
        delete[] array;
    }
    unsigned int size()
    {
        return this->_size;
    }
    T &operator[](unsigned int size)
    {
        if (_size == 0)
            throw exc();
        if (size > this->_size - 1)
            throw exc();
        return this->array[size];
    }
    class exc : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Exception catched: Out of bounds\n";
        }
    };
};

