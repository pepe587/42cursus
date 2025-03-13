#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap created" << std::endl;
    this->name = name;
    health = 100;
    energy = 50;
    damage = 20;
}

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap created" << std::endl;
    this->name = "pepe";
    health = 100;
    energy = 50;
    damage = 20;
}

ScavTrap::ScavTrap(ScavTrap &a)
{
    std::cout << "ScavTrap created" << std::endl;
    this->name = a.name;
    health = a.health;
    energy = a.energy;
    damage = a.damage;
}

ScavTrap &ScavTrap::operator=(ScavTrap &cpy)
{
    this->name = cpy.name;
    health = cpy.health;
    energy = cpy.energy;
    damage = cpy.damage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destroyed" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap" << this->name <<"is now in Gate keeper mode" << std::endl;
}