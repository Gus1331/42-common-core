#include "WrongCat/WrongCat.hpp"

/* Constructors */

WrongCat::WrongCat() {
    cout << "<WrongCat constructor>" << endl;
}

WrongCat::WrongCat(string type) {
    cout << "<WrongCat constructor>" << endl;
    WrongAnimal::setType(type);
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    *this = other;
}

WrongCat::~WrongCat() {
    cout << "<WrongCat destructor>" << endl;
}

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
