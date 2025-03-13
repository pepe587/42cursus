#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name (name), health (10), energy (10), damage (0)
{
    std::cout << "ClapTrap " << name << " initialized" << std::endl;
}

ClapTrap::ClapTrap() :  name ("Pepe"), health (10), energy (10), damage (0)
{}

ClapTrap::ClapTrap(ClapTrap &a)
{
    name = a.name;
    health = a.health;
    energy = a.energy;
    damage = a.damage;
}

ClapTrap &ClapTrap::operator=(ClapTrap &cpy)
{
    name = cpy.name;
    health = cpy.health;
    energy = cpy.energy;
    damage = cpy.damage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target
        << ", causing " << this->damage << " points of damage!" << std::endl;
        this->energy--;
    }
    else
        std::cout << "ClapTrap can’t do anything" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy > 0)
    {
        std::cout << "ClapTrap " << this->name << " has been repaired " << amount << " points" << std::endl;
        this->health += amount;
        this->energy--;
    }
    else
        std::cout << "ClapTrap can’t do anything" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " has been damaged " << amount << " points" << std::endl;
    this->health -= amount;
}