#include "WrongAnimal/WrongAnimal.hpp"


/* Constructors */

WrongAnimal::WrongAnimal() : type("Not Live Being") {
}

WrongAnimal::WrongAnimal(string type) : type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    *this = other;
}

WrongAnimal::~WrongAnimal() {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        this->setType(other.type);
    }
    return *this;
}

/* Methods */

void WrongAnimal::makeSound(void) const{
    cout << "*wrong animal noises*" << endl;
}

/* Getters and setters */

string WrongAnimal::getType(void) const{
    return this->type;
}

void WrongAnimal::setType(string type) {
    this->type = type;
}
