#include "Zombie.hpp"

int main(void)
{
    Zombie zmb;
    Zombie *horde;
    int     i;

    horde = zmb.zombieHorde(12, "Mimi");
    i = 0;
    while (i < 12)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
}