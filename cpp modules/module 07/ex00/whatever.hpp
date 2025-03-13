#pragma once

template <typename T>
T max(T i, T o)
{
    if (i > o)
        return i;
    else
        return o;
}

template <typename T>
T min(T i, T o)
{
    if (i < o)
        return i;
    else
        return o;
}

template <typename T>
void swap(T &i, T &o)
{
    T a;
    a = i; 
    i = o;
    o = a;
}