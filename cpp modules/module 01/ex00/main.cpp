#include "Zombie.hpp"

int main(void)
{
    Zombie juan("juan");
    Zombie *pepe;
    juan.announce();
    pepe = juan.newZombie("pepe");
    pepe->randomChump("sofia");
    pepe->announce();
    delete pepe;
}