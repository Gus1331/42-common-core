#include "Character/Character.hpp"

/* Constructors */

Character::Character() : name("Unkown") {
    for (int i = 0; i < 4; i++) {
            this->inventory[i] = NULL;
    }
}

Character::Character(string const &name) : name(name) {
    for (int i = 0; i < 4; i++) {
            this->inventory[i] = NULL;
    }
}

Character::Character(const Character &other) {
    this->operator=(other);
}


Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

/* Methods */
void Character::use(int idx, ICharacter& target) {

    if (idx < 0 || idx > 3 || !this->inventory[idx]) {
        cout << this->getName() << " didn't had a wepon on slot " << idx << " to attack!" << endl;
        return;
    }
    this->inventory[idx]->use(target);
}

void Character::equip(AMateria* m) {
    int i = 0;
    while (this->inventory[i]) i++;
    if (i >= 4) {
        unequip(1);
        i = 3;
    }
    this->inventory[i] = m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) return;
    this->inventory[idx] = NULL;
    for (int i = idx; i < 3; i++) {
        this->inventory[i] = this->inventory[i + 1];
        this->inventory[i + 1] = NULL;
    }
}

/* Getters and Setters */

string const &Character::getName(void) const {
    return this->name;
}

void Character::setName(string name) {
    this->name = name;
}

