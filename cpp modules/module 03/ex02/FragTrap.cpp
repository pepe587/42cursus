#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap created" << std::endl;
    this->name = name;
    health = 100;
    energy = 100;
    damage = 30;
}

FragTrap::FragTrap()
{
    std::cout << "FragTrap created" << std::endl;
    this->name = "pepe";
    health = 100;
    energy = 100;
    damage = 30;
}

FragTrap::FragTrap(FragTrap &a)
{
    std::cout << "FragTrap created" << std::endl;
    this->name = a.name;
    health = a.health;
    energy = a.energy;
    damage = a.damage;
}

FragTrap &FragTrap::operator=(FragTrap &cpy)
{
    this->name = cpy.name;
    health = cpy.health;
    energy = cpy.energy;
    damage = cpy.damage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap: Give me five!!" << std::endl;
}