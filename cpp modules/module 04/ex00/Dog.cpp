#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog created" << std::endl;
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(Dog &a)
{
    this->type = a.type;
}

Dog &Dog::operator=(Dog &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Guauuuuuuu" << std::endl;
}
