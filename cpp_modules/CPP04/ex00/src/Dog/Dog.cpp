#include "Dog/Dog.hpp"

/* Constructors */

Dog::Dog() {
    cout << "<Dog constructor>" << endl;
    Animal::setType("Canine");
}

Dog::Dog(string type) {
    cout << "<Dog constructor>" << endl;
    Animal::setType(type);
}

Dog::Dog(const Dog &other) : Animal(other) {
    *this = other;
}

Dog::~Dog() {
    cout << "<Dog constructor>" << endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

/* Methods */

void Dog::makeSound(void) const {
    cout << "Auuuuf :U 🐕🐶🦴" << endl;
}
