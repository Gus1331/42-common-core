#include "Cat/Cat.hpp"

/* Constructors */

Cat::Cat() {
}

Cat::Cat(string type) {
    Animal::setType(type);
}

Cat::Cat(const Cat &other) : Animal(other) {
    *this = other;
}

Cat::~Cat() {}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

/* Methods */

void Cat::makeSound(void) const {
    cout << "Meown :3 🐈🐱🧶" << endl;
}
