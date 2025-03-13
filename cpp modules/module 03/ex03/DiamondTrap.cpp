#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap created" << std::endl;
    this->name = name;
    ClapTrap::name = this->name + "_clap_name";
}

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap created" << std::endl;
    this->name = "pepe";
    ClapTrap::name = this->name + "_clap_name";
}

DiamondTrap::DiamondTrap(DiamondTrap &a)
{
    std::cout << "DiamondTrap created" << std::endl;
    this->name = a.name;
    ClapTrap::name = this->name + "_clap_name";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->name
    << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}