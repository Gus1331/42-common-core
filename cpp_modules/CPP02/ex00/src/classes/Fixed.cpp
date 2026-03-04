#include "Fixed.hpp"

Fixed::Fixed () {
    cout << "Default constructor..." << endl;
    fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other) {
    cout << "Copy constructor" << endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
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

Fixed::~Fixed(){
    cout << "Destructor..." << endl;
}