
#include <iostream>
#include <string.h>
#include "Bureaucrat/Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    std::cout << "===== Default Constructor =====" << std::endl;
    Bureaucrat a;
    std::cout << a.getName() << ", grade " << a.getGrade() << std::endl;

    std::cout << "\n===== Parameterized Constructor =====" << std::endl;
    try {
        Bureaucrat b("Arlong", 42);
        std::cout << b.getName() << ", grade " << b.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Invalid Grade (Too High) =====" << std::endl;
    try {
        Bureaucrat c("Perospero", 0);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Invalid Grade (Too Low) =====" << std::endl;
    try {
        Bureaucrat d("Duval", 151);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Increment / Decrement =====" << std::endl;
    try {
        Bureaucrat e("Chopper", 2);

        std::cout << "Initial: " << e.getGrade() << std::endl;

        e.increment();
        std::cout << "After increment: " << e.getGrade() << std::endl;

        e.increment(); // Should throw
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat f("Perona", 149);

        std::cout << "Initial: " << f.getGrade() << std::endl;

        f.decrement();
        std::cout << "After decrement: " << f.getGrade() << std::endl;

        f.decrement(); // Should throw
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Copy Constructor =====" << std::endl;
    Bureaucrat original("Franky", 50);
    Bureaucrat copy(original);

    std::cout << "Original: " << original << endl;
    std::cout << "Copy: " << copy << std::endl;

    std::cout << "\n===== Assignment Operator =====" << std::endl;
    Bureaucrat l("Luffy", 100);
    Bureaucrat z("Zoro", 25);

    l = z;

    std::cout << "l: " << l << std::endl;
    std::cout << "z: " << z << std::endl;

    return 0;
}
