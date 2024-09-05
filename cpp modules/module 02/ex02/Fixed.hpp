
#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int num;
    static const int bits = 8;

public:

    /********* CONSTRUCTOR *********/

    Fixed();
    Fixed(Fixed const &a);
    Fixed(const int a);
    Fixed(const float num);
    ~Fixed();
    
    /********* OPERATORS *********/

    Fixed &operator/(Fixed a);
    Fixed &operator-(Fixed a);
    Fixed &operator+(Fixed a);
    Fixed &operator*(Fixed a);
    Fixed &operator=(Fixed a);
    bool operator==(Fixed a);
    bool operator!=(Fixed a);
    bool operator>(Fixed a);
    bool operator>=(Fixed a);
    bool operator<(Fixed a);
    bool operator<=(Fixed a);
    Fixed operator++(void);
    Fixed operator--(void);
    Fixed operator++(int a);
    Fixed operator--(int a);

    /********* FUNCTIONS *********/

    int           getRawBits(void) const;
    void          setRawBits(int const raw);
    float         toFloat(void) const;
    int           toInt(void) const;
    int           get_num(void);
    static  Fixed       &min(Fixed &a, Fixed &b);
    static  Fixed       &max(Fixed &a, Fixed &b);
    static  const Fixed &min(const Fixed &a, const Fixed &b);
    static  const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, Fixed a);

#endif