#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(): name(""), weapon(NULL) {}
HumanB::HumanB(string name): name(name) {this->weapon = NULL;}

void HumanB::attack(void) {
    if (weapon == NULL)
        cout << name << " attacks with their bare hands" << endl;
    else
        cout << name << " attacks with their " << weapon->getType() << endl;
}

string HumanB::getName() const {return name;}
void HumanB::setName(const string &name_) {name = name_;}

Weapon HumanB::getWeapon() const {return *weapon;}
void HumanB::setWeapon(Weapon& weapon_) {weapon = &weapon_;}