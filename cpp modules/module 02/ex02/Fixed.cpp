
#include "Fixed.hpp"

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.num > b.num)
        return b;
    else
        return a;
}
Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.num > b.num)
        return b;
    else
        return a;
}
Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.num > b.num)
        return a;
    else
        return b;
}
Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.num > b.num)
        return a;
    else
        return b;
}    


Fixed Fixed::operator--(void)
{
    this->num--;
    return this->num;
}

Fixed Fixed::operator--(int a)
{
    a = this->num;
    this->num--;
    return static_cast<Fixed>(a);
}

Fixed Fixed::operator++(int a)
{
    a = this->num;
    this->num++;
    return static_cast<Fixed>(a);
}

Fixed Fixed::operator++(void)
{
    this->num++;
    return this->num;
}

Fixed &Fixed::operator/(Fixed a)
{
    this->num /= a.num;
    return *this;
}

Fixed &Fixed::operator+(Fixed a)
{
    this->num += a.num;
    return *this;
}

Fixed &Fixed::operator*(Fixed a)
{
    this->num *= a.num;
    return *this;
}

bool Fixed::operator!=(Fixed a)
{
    return (this->num != a.num);
}

bool Fixed::operator==(Fixed a)
{
    return (this->num == a.num);
}

bool Fixed::operator>(Fixed a)
{
    return this->num > a.num;
}

bool Fixed::operator>=(Fixed a)
{
    return this->num >= a.num;
}

bool Fixed::operator<(Fixed a)
{
    return this->num < a.num;
}

bool Fixed::operator<=(Fixed a)
{
    return this->num <= a.num;
}

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
    //std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int a)
{
    this->num = a;
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed()
{
    this->num = 0;
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed a)
{
    this->num = a.num;
    //std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::Fixed(Fixed const &a)
{
    this->num = a.num;
    //std::cout << "Copy constructor called" << std::endl;
}

int    Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->num;
}

void    Fixed::setRawBits(int const raw)
{
    this->num = raw;
}