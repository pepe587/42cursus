
#include "Fixed.hpp"

Fixed::Fixed()
{
    this->num = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed a)
{
    this->num = a.num;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::Fixed(Fixed &a)
{
    this->num = a.num;
    std::cout << "Copy constructor called" << std::endl;
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->num;
}

void    Fixed::setRawBits(int const raw)
{
    this->num = raw;
}