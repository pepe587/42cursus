#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
    int random;

    random = rand() % 100 + 1;
    if (random <= 33)
        return new A;
    if (random > 33 && random <= 66)
        return new B;
    if (random > 66)
        return new C;
    return NULL;
}
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Class Type: A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Class Type: B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Class Type: C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        p = dynamic_cast<A &>(p);
        std::cout << "Class Type: A" << std::endl;
    }
    catch(const std::exception& e)
    {}
    try
    {
        p = dynamic_cast<B &>(p);
        std::cout << "Class Type: B" << std::endl;
    }
    catch(const std::exception& e)
    {}
    try
    {
        p = dynamic_cast<C &>(p);
        std::cout << "Class Type: C" << std::endl;
    }
    catch(const std::exception& e)
    {}
}

int main()
{
    srand(time(0));
    Base *random = generate();
    Base *random2 = generate();
    Base *random3 = generate(); 

    identify(random);
    identify(*random);
    identify(random2);
    identify(*random2);
    identify(random3);
    identify(*random3);
    delete random;
    delete random2;
    delete random3;
    return 0;
}
