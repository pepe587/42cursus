
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

    class ClapTrap
    {
        protected:
            std::string name;
            int health;
            int energy;
            int damage;
        public:
            void attack(const std::string &target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);
            ClapTrap();
            ClapTrap(std::string name);
            ClapTrap(ClapTrap &a);
            ~ClapTrap();
            ClapTrap &operator=(ClapTrap &cpy);

    };
    

#endif