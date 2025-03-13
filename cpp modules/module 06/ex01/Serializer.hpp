#pragma once
#include <iostream>
#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
private:
    Serializer();
public:
    ~Serializer();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};