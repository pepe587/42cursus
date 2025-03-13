#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t ptr_num;

    ptr_num = reinterpret_cast<uintptr_t>(ptr);
    return ptr_num;
}


Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr;

    ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}