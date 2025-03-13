#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap m("mimi");
    ClapTrap b("benja");

    int i = 0;
    
    m.takeDamage(10);
    m.attack("benja");
    while (i++ < 11)
        m.beRepaired(1);
}