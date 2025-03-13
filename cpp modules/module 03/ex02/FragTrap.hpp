#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap();
    FragTrap(FragTrap &a);
    FragTrap &operator=(FragTrap &cpy);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif