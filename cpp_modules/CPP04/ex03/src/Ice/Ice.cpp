#include "Ice/Ice.hpp"

Ice::Ice() {
    this->AMateria::type = "ice";
}

Ice::Ice(std::string const & type) {
    this->type = type;
}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

/* Methods */

AMateria* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    cout << this->AMateria::getType() << ": \"* shoots an ice bolt at " << target.getName() << " *\"" << endl;
}

