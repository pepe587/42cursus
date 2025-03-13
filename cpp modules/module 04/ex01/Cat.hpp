#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *br;
public:
    Cat();
    ~Cat();
    Cat(Cat &a);
    Cat &operator=(Cat &cpy);
    void makeSound() const;
};

#endif