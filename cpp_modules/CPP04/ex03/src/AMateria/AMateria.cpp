#include "AMateria/AMateria.hpp"

/* Constructors */

AMateria::AMateria() : type("Unknown") {}

AMateria::AMateria(string const & type) : type(type) {}

AMateria::AMateria(const AMateria &other) {
    *this = other;
}
AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}

AMateria::~AMateria() {}

/* Methods */

void AMateria::use(ICharacter& target) {
    cout << this->getType() << ": \"* does something to " << target.getName() << " *\"" << endl;
}

/* Getters and setters */

string const &AMateria::getType() const {
    return this->type;
}
