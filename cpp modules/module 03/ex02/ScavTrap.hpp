
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string name);
    ScavTrap();
    ScavTrap(ScavTrap &a);
    ScavTrap &operator=(ScavTrap &cpy);
    ~ScavTrap();
    void guardGate();
};

#endif