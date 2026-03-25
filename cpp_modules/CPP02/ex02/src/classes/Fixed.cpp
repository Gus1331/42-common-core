#include "Fixed.hpp"

Fixed::Fixed () {
    this->setRawBits(0);
}

Fixed::Fixed (int value) {
    this->setRawBits(value << fractionalBits);
}

Fixed::Fixed (float value) {
    this->setRawBits(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->fixedPoint = other.getRawBits();
    }
    return *this;
}

Fixed Fixed::operator+(const Fixed &other) {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return temp;
}

Fixed &Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return temp;
}

bool Fixed::operator==(const Fixed &other) {
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) {
    return (this->getRawBits() != other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) {
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) {
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) {
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) {
    return (this->getRawBits() < other.getRawBits());
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
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a < b) return b;
    return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() < b.getRawBits()) return b;
    return a;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a > b) return b;
    return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() > b.getRawBits()) return b;
    return a;
}


ostream& operator<<(ostream &os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}
