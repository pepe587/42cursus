#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{

public:
    Dog();
    ~Dog();
    Dog(Dog &a);
    Dog &operator=(Dog &cpy);
    void makeSound() const;
};

#endif