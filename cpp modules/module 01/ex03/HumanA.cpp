
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wpn) : name (name), wpn (wpn)
{
    return ;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->wpn.getType() << std::endl;
}