
#ifndef __FIXED_H__
#define __FIXED_H__

#include <string>
#include <iostream>
#include <cmath>

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
        Fixed (int value);
        Fixed (float value);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        ~Fixed();

        bool operator==(const Fixed &other);
        bool operator!=(const Fixed &other);
        bool operator>=(const Fixed &other);
        bool operator<=(const Fixed &other);
        bool operator>(const Fixed &other);
        bool operator<(const Fixed &other);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
};

ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif

