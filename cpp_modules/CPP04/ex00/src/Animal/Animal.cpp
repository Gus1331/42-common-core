#include "Animal/Animal.hpp"


/* Constructors */

Animal::Animal() {
    cout << "<Animal constructor>" << endl;
    this->type = "unkown";
}

Animal::Animal(string type) : type(type) {
    cout << "<Animal constructor>" << endl;
}

Animal::Animal(const Animal &other) {
    *this = other;
}

Animal::~Animal() {
    cout << "<Animal destructor>" << endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        this->setType(other.type);
    }
    return *this;
}

/* Methods */

void Animal::makeSound(void) const{
    cout << "What does the fox say?" << endl;
}

/* Getters and setters */

string Animal::getType(void) const{
    return this->type;
}

void Animal::setType(string type) {
    this->type = type;
}
