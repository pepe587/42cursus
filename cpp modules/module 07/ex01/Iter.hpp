#pragma once

template <typename T, typename U>
void iter(T *array, unsigned int size, U (*func)(T&))
{
    if (!array || !size)
        return ;
    for (unsigned int i = 0; i < size; i++)
        func(array[i]);
}