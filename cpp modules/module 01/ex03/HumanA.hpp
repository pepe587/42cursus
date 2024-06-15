#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
    private:
    std::string name;
    Weapon &wpn;
    public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void){}
    void attack(void);
};

#endif