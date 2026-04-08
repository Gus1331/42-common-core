
#ifndef __POINT_H__
#define __POINT_H__

#include <string>
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#pragma once
class Point;

using std::string;
using std::cout;
using std::endl;

class Point {
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point ();
        Point (const float x, const float y);
        Point(const Point &other);
        ~Point();
    
        Point &operator=(const Point &other);

        Fixed const getY(void) const;
        Fixed const getX(void) const;
};

#endif

