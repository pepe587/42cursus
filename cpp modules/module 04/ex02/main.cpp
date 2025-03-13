#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    /*const Animal* meta = new Animal();*/ //NOT ALLOWED BECAUSE ITS A ABSTRACT CLASS
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Cat *pp = new Cat;
    Cat *l = new Cat(*pp);
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    l->makeSound();

    delete pp;
    delete l;
    delete i;
    delete j;
    return 0;
}
