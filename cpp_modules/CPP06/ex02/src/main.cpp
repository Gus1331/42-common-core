#include "Base/Base.hpp"
#include "A/A.hpp"
#include "B/B.hpp"
#include "C/C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void) {
    int rng = (std::rand() % 3);

    Base *res;
    char l[3] = {'A', 'B', 'C'};

    switch (rng) {
        case 0:
            res = new A();
            break;
        case 1:
            res = new B();
            break;
        case 2:
            res = new C();
            break;
    }

    std::cout << "generated " << l[rng] << " class" << std::endl;
    return res;
}

void identify(Base* p) {
    A * ba = dynamic_cast<A*>(p);
    if (ba != NULL) {
        std::cout << "* -> A" << std::endl;
        return;
    }

    B * bb = dynamic_cast<B*>(p);
    if (bb != NULL) {
        std::cout << "* -> B" << std::endl;
        return;
    }

    C * bc = dynamic_cast<C*>(p);
    if (bc != NULL) {
        std::cout << "* -> C" << std::endl;
        return;
    }

    std::cout << "* -> Error" << std::endl;
}

void identify(Base& p) {
    A * ba = dynamic_cast<A*>(&p);
    if (ba != NULL) {
        std::cout << "& -> A" << std::endl;
        return;
    }

    B * bb = dynamic_cast<B*>(&p);
    if (bb != NULL) {
        std::cout << "& -> B" << std::endl;
        return;
    }

    C * bc = dynamic_cast<C*>(&p);
    if (bc != NULL) {
        std::cout << "& -> C" << std::endl;
        return;
    }

    std::cout << "-> Error" << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    for(int i = 0; i < 10; i++) {
        Base *b = generate();
        identify(b);
        identify(*b);
        std::cout << std::endl;
        delete(b);
    }
    return 0;
}