#include "Dog/Dog.hpp"

/* Constructors */

Dog::Dog() : brain(new Brain) {
}

Dog::Dog(string type) {
    Animal::setType(type);
}

Dog::Dog(const Dog &other) : Animal(other) {
    *this = other;
}

Dog::~Dog() {
    delete brain;
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

/* Getters and setters */
Brain &Dog::getBrain(void) {
    return *this->brain;
}
