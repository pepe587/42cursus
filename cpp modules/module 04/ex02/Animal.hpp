#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(Animal &a);
    Animal &operator=(Animal &cpy);
    virtual ~Animal();
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif