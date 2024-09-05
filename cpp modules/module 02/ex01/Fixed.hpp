
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 num;
        static const int    bits = 8;
    public:
        Fixed();
        Fixed(Fixed const &a);
        Fixed(const int a);
        Fixed(const float num);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;
        Fixed &operator=(Fixed a);
};

std::ostream &operator<<(std::ostream &os, Fixed a);

#endif