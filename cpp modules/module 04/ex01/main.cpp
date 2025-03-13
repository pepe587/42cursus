#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal *animals[100];
    int i = 0;

    while (i < 50)
    {
        animals[i] = new Dog();
        i++;
    }
    while (i < 100)
    {
        animals[i] = new Cat();
        i++;
    }
    i = 0;
    const Cat *xd = dynamic_cast<const Cat*>(animals[57]);
    xd->makeSound();
    while (i < 100)
    {
        delete animals[i];
        i++;
    }
    return 0;
}
