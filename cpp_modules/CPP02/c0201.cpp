#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Fixed {
    private:
        int fixedPoint;
        static const int fractionalBits = 8;
    public:
        Fixed () {
            cout << "Default constructor..." << endl;
            fixedPoint = 0;
        }
        Fixed(const Fixed &other) {
            cout << "Copy constructor" << endl;
            *this = other;
        }

        Fixed (const int fixedPoint): fixedPoint(fixedPoint) {}

        Fixed (const float fixedPoint): fixedPoint((int)fixedPoint) {}

        Fixed &operator=(const Fixed &other) {
            cout << "Assign operator..." << endl;
            if (this != &other) {
                this->fixedPoint = other.getRawBits();
            }
            return *this;
        }

        float toFloat(void) const {
            return (float)this->getRawBits();
        }

        int toInt(void) const {
            return this->getRawBits();
        }

        int getRawBits(void) const {
            cout << "getRawBits..." << endl;
            return fixedPoint;
        }

        void setRawBits(int const raw) { fixedPoint = raw; }
        ~Fixed(){
            cout << "Destructor..." << endl;
        }
};

ostream &operator<<(ostream &os, const Fixed& obj) {
    os << obj.getRawBits();
    return os;
}

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}
