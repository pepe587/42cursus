#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    virtual ~WrongCat();
    WrongCat(WrongCat &a);
    WrongCat &operator=(WrongCat &cpy);
    void makeSound() const;
};






#endif