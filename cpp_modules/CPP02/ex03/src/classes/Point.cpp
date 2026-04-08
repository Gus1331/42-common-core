#include "Point.hpp"

Point::Point () : x(Fixed(0)), y(Fixed(0)) {}

Point::Point (const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point &other) {
    (void)other;
    return *this;
}

Point::~Point(){
}

Fixed const Point::getY(void) const {
    return this->y;
}

Fixed const Point::getX(void) const {
    return this->x;
}
