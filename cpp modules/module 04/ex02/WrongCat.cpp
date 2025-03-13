#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat created" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &a)
{
    *this = a;
}

WrongCat &WrongCat::operator=(WrongCat &cpy)
{
    if (this != &cpy)
    {
        this->type = cpy.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Miauuuuuu" << std::endl;
}
