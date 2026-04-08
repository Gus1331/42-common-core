#include "WrongCat/WrongCat.hpp"

/* Constructors */

WrongCat::WrongCat() {
}

WrongCat::WrongCat(string type) {
    WrongAnimal::setType(type);
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    *this = other;
}

WrongCat::~WrongCat() {}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

/* Methods */

void WrongCat::makeSound(void) const {
    cout << "Fake Meown 3: 🐈🐱🧶" << endl;
}
