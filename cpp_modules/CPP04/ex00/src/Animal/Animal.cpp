#include "Animal/Animal.hpp"


/* Constructors */

Animal::Animal() {
}

Animal::Animal(string type) : type(type) {}

Animal::Animal(const Animal &other) {
    *this = other;
}

Animal::~Animal() {}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        this->setType(other.type);
    }
    return *this;
}

/* Methods */

void Animal::makeSound(void) {
    cout << "What does the fox say?" << endl;
}

/* Getters and setters */

string Animal::getType(void) {
    return this->type;
}

void Animal::setType(string type) {
    this->type = type;
}
