#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    private:
    std::string name;
    Weapon *wpn;
    public:
    HumanB(std::string name);
    ~HumanB(void){}
    void attack(void);
    void setWeapon(Weapon &wpn);
};

#endif