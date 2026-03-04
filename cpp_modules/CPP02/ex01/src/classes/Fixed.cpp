#include "Fixed.hpp"

Fixed::Fixed () {
    cout << "Default constructor..." << endl;
    fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other) {
    cout << "Copy constructor" << endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
    cout << "Assign operator..." << endl;
    if (this != &other) {
        this->fixedPoint = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    cout << "getRawBits..." << endl;
    return fixedPoint;
}

void Fixed::setRawBits(int const raw) { fixedPoint = raw; }


float Fixed::toFloat(void) const {
    return (float)this->getRawBits();
}

int Fixed::toInt(void) const {
    return this->getRawBits();
}

Fixed::~Fixed(){
    cout << "Destructor..." << endl;
}

ostream& Fixed:operator<<(ostream &os, const Fixed& obj) {
    os << obj.getRawBits();
    return os;
}
