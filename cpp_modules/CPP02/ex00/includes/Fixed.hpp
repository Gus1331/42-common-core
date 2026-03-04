
#ifndef __FIXED_H__
#define __FIXED_H__

#include <string>
#include <iostream>

#pragma once
class Fixed;

using std::string;
using std::cout;
using std::endl;

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
};

#endif

