#include "Dog/Dog.hpp"

/* Constructors */

Dog::Dog() : brain(new Brain) {
}

Dog::Dog(string type) {
    AAnimal::setType(type);
}

Dog::Dog(const Dog &other) : AAnimal(other) {
    *this = other;
}

Dog::~Dog() {
    delete brain;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain();
        *this->brain = other.getBrain();
    }
    return *this;
}

/* Methods */

void Dog::makeSound(void) const {
    cout << "Auuuuf :U 🐕🐶🦴" << endl;
}

/* Getters and setters */
Brain &Dog::getBrain(void) const{
    return *this->brain;
}
