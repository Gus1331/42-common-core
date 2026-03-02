#include "Weapon.hpp"

Weapon::Weapon (): type ("") {}
Weapon::Weapon(string type) : type(type) {}

string Weapon::getType() {return type;}
void Weapon::setType(string type) {this->type = type;}
