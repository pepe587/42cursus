
#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &os, Fixed a)
{
    os << a.toFloat();
    return os;
}

int     Fixed::toInt(void) const
{
    return (this->num * (1 << this->bits));
}

float   Fixed::toFloat(void) const
{
    return ((float)this->num / (1 << this->bits));
}

Fixed::Fixed(const float num)
{
    this->num = roundf(num * (1 << this->bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int a)
{
    this->num = a;
    std::cout << "Int constructor called" << std::endl;
}

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

Fixed::Fixed(Fixed const &a)
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