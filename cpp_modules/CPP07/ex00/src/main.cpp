#include "whatever.hpp"
#include <iostream>

using std::cout;
using std::endl;

int	main() {
    int a = 42;
    int b = -42;

    cout << "min: " << min(a, b) << endl;
    cout << "max: " << max(a, b) << endl;

    cout << "B4 swap: a=" << a << "; b=" << b  << ";" << endl;
    swap(a, b);
    cout << "After swap: a=" << a << "; b=" << b  << ";" << endl;

    cout << "min: " << min(a, b) << endl;
    cout << "max: " << max(a, b) << endl;
return (0);
}

/* // main's subject

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}

*/
