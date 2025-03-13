#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data("Data");
    uintptr_t raw;

    std::cout << ptr << std::endl;
    raw = Serializer::serialize(ptr);
    std::cout << "0x" << std::hex << raw << std::dec << std::endl;
    std::cout << std::endl << "--------------------------" << std::endl << std::endl;
    std::cout << ptr->getData() << std::endl;
    ptr = Serializer::deserialize(raw);
    std::cout << ptr->getData() << std::endl;
    delete ptr;
    return 0;
}
