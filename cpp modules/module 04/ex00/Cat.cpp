#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat created" << std::endl;
    type = "Cat";
}

Cat::Cat(Cat &a)
{
    this->type = a.type;
}

Cat &Cat::operator=(Cat &cpy)
{
    if (this != &cpy)
        this->type = cpy.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miauuuuuu" << std::endl;
}
