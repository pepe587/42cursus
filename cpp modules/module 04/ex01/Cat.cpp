#include "Cat.hpp"


Cat::Cat()
{
    std::cout << "Cat created" << std::endl;
    type = "Cat";
    br = new Brain;
}

Cat::Cat(Cat &a)
{
    this->type = a.type;
    this->br = new Brain(*a.br);
}

Cat &Cat::operator=(Cat &cpy)
{
    if (this != &cpy)
    {
        this->type = cpy.type;
        this->br = new Brain(*cpy.br);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
    delete br;
}

void Cat::makeSound() const
{
    std::cout << "Miauuuuuu" << std::endl;
}
