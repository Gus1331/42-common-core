#include "WrongAnimal/WrongAnimal.hpp"


/* Constructors */

WrongAnimal::WrongAnimal() : type("Not Live Being") {
        cout << "<WrongAnimal constructor>" << endl;
}

WrongAnimal::WrongAnimal(string type) : type(type) {
        cout << "<WrongAnimal constructor>" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    *this = other;
}

WrongAnimal::~WrongAnimal() {
    cout << "<WrongAnimal destructor>" << endl;
}

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
