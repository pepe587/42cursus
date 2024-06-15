#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
    int i;
    Zombie  *horde = new Zombie[N];

    i = 0;
    while (i < N)
    {
        horde[i].setname(name);
        i++;
    }
    return (horde);
}