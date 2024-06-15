#include <iostream>
#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}