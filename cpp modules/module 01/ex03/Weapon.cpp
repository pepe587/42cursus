#include "Weapon.hpp"

void Weapon::setType(std::string new_type)
{
    this->type = new_type;
}

const std::string &Weapon::getType(void)
{
    std::string &cpy = this->type;
    return (cpy);
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::Weapon(){}
Weapon::~Weapon(){}