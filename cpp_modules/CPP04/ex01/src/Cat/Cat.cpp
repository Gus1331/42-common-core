#include "Cat/Cat.hpp"

/* Constructors */

Cat::Cat() : brain(new Brain) {
}

Cat::Cat(string type) {
    Animal::setType(type);
}

Cat::Cat(const Cat &other) : Animal(other) {
    *this = other;
}

Cat::~Cat() {
    delete this->brain;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        *this->brain = other.Cat::getBrain();
        if (this->brain && other.brain) {
            *this->brain = *other.brain;
        }
    }
    return *this;
}

/* Methods */

void Cat::makeSound(void) const {
    cout << "Meown :3 🐈🐱🧶" << endl;
}

/* Getters and setters */
Brain &Cat::getBrain(void) const{
    return *this->brain;
}
