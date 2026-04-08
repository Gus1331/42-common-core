#include "AAnimal/AAnimal.hpp"


/* Constructors */

AAnimal::AAnimal() : type("Live Being") {
}

AAnimal::AAnimal(string type) : type(type) {}

AAnimal::AAnimal(const AAnimal &other) {
    *this = other;
}

AAnimal::~AAnimal() {}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    if (this != &other) {
        this->setType(other.type);
    }
    return *this;
}

/* Methods */

void AAnimal::makeSound(void) const{
    cout << "What does the fox say?" << endl;
}

/* Getters and setters */

string AAnimal::getType(void) const{
    return this->type;
}

void AAnimal::setType(string type) {
    this->type = type;
}
