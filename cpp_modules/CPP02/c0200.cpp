#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

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

        Fixed &operator=(const Fixed &other) {
            cout << "Assign operator..." << endl;
            if (this != &other) {
                this->fixedPoint = other.getRawBits();
            }
            return *this;
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

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
