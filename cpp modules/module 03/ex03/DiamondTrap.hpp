#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string name;
public:
    DiamondTrap(std::string name);
    DiamondTrap();
    DiamondTrap(DiamondTrap &a);
    DiamondTrap &operator=(DiamondTrap &cpy);
    ~DiamondTrap();
    void whoAmI();
};
