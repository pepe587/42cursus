#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name (name), wpn (NULL)
{
    return ;
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << this->wpn->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &wpn)
{
    this->wpn = &wpn;
}