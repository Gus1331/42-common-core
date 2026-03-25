#include "Fixed.hpp"

Fixed::Fixed () {
    cout << "Default Constructor..." << endl;
    this->setRawBits(0);
}

Fixed::Fixed (int value) {
    cout << "Int Constructor..." << endl;
    this->setRawBits(value << fractionalBits);
}

Fixed::Fixed (float value) {
    cout << "Float Constructor..." << endl;
    this->setRawBits(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &other) {
    cout << "Copy constructor..." << endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
    cout << "Copy assign operator..." << endl;
    if (this != &other) {
        this->fixedPoint = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    return fixedPoint;
}

void Fixed::setRawBits(int const raw) { fixedPoint = raw; }


float Fixed::toFloat(void) const {
    return (float)(this->getRawBits()) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return ((int)this->getRawBits() >> fractionalBits);
}

Fixed::~Fixed(){
    cout << "Destructor..." << endl;
}

ostream& operator<<(ostream &os, const Fixed& obj) {
        os << obj.toFloat();
    return os;
}
