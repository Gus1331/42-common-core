
#ifndef __FIXED_H__
#define __FIXED_H__

#include <string>
#include <iostream>

#pragma once
class Fixed;

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Fixed {
    private:
        int fixedPoint;
        static const int fractionalBits = 8;
    public:
        Fixed ();
        Fixed(const Fixed &other);

        Fixed &operator=(const Fixed &other);

        int getRawBits(void) const;

        void setRawBits(int const raw);
        ~Fixed();

        float toFloat(void) const;

        int toInt(void) const;

        void setRawBits(int const raw);
};

ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif

