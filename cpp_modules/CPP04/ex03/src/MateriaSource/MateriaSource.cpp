#include "MateriaSource/MateriaSource.hpp"

/* Constructors */
MateriaSource::MateriaSource() : name("Unkown") {
    for (int i = 0; i < 4; i++) {
        this->learned[i] = NULL;
    }
}

MateriaSource::MateriaSource(string const &name) : name(name) {
    for (int i = 0; i < 4; i++) {
        this->learned[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    *this = other;
}


MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->learned[i])
            delete this->learned[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

/* Methods */
void MateriaSource::learnMateria(AMateria* m) {
    for(int i = 0; i < 3;  i++) {
        if (!this->learned[i]) {
            this->learned[i] = m;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(string const & type) {
    if (type == "Unkown") return 0;
    for(int i = 0; i < 3 && this->learned[i];  i++) {
        if (this->learned[i]->getType() == type)
            return this->learned[i]->clone();
    }
    return 0;
}
