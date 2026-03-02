
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(string name, Weapon& weapon) : name(name), weapon(weapon) {}


void HumanA::attack(void) {
    cout << name << " attacks with their " << weapon.getType() << endl;
}


string HumanA::getName() const { return name; }
void HumanA::setName(const string &name_) { name = name_; }

Weapon HumanA::getWeapon() { return weapon; }
void HumanA::setWeapon(Weapon weapon_) { this->weapon = weapon_; }
