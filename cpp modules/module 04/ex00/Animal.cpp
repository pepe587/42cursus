#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal created" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "*noise*" << std::endl;
}

Animal::Animal(Animal &a)
{
    this->type = a.type;
}

Animal &Animal::operator=(Animal &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return *this;
}
