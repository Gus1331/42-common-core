#include "Cure/Cure.hpp"

Cure::Cure() {
    this->AMateria::type = "cure";
}

Cure::Cure(std::string const & type) {
    this->type = type;
}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

/* Methods */

AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    cout << this->AMateria::getType() << ": \"* heals " << target.getName() << "'s wounds *\"" << endl;
}

