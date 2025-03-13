#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain &a)
{
    *this = a;
}

Brain &Brain::operator=(Brain &cpy)
{
    if (this != &cpy)
    {
        int i = 0;
        while (!ideas[i].empty())
        {
            ideas[i] = cpy.ideas[i]; 
            i++;
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}
