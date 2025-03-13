#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog created" << std::endl;
    type = "Dog";
    br = new Brain;
}

Dog::Dog(Dog &a)
{
    this->type = a.type;
    this->br = new Brain(*a.br);
}

Dog &Dog::operator=(Dog &cpy)
{
    if (this != &cpy)
    {
        this->type = cpy.type;
        this->br = new Brain(*cpy.br);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed" << std::endl;
    delete br;
}

void Dog::makeSound() const
{
    std::cout << "Guauuuuuuu" << std::endl;
}
