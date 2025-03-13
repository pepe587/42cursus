#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    Cat(Cat &a);
    Cat &operator=(Cat &cpy);
    void makeSound() const;
};

#endif