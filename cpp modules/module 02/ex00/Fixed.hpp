
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int                 num;
        static const int    bits = 8;
    public:
        Fixed();
        Fixed(Fixed &a);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed &operator=(Fixed a);
};

#endif