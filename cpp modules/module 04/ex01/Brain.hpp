#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
public:
    Brain();
    ~Brain();
    Brain(Brain &a);
    Brain &operator=(Brain &cpy);
    std::string ideas[100];
};



#endif