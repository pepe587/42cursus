#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Animal created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &a)
{
    this->type = a.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &cpy)
{
    this->type = cpy.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Animal destroyed" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "NOISE" << std::endl;
}