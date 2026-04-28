#include "Cat/Cat.hpp"

/* Constructors */

Cat::Cat() {
    cout << "<Cat constructor>" << endl;
    Animal::setType("Feline");
}

Cat::Cat(string type) {
    cout << "<Cat constructor>" << endl;
    Animal::setType(type);
}

Cat::Cat(const Cat &other) : Animal(other) {
    *this = other;
}

Cat::~Cat() {
    cout << "<Cat destructor>" << endl;
}

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
