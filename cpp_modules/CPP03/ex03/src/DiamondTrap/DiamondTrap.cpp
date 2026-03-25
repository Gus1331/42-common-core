#include "DiamondTrap/DiamondTrap.hpp"

/* Constructors */

DiamondTrap::DiamondTrap() {
    ClapTrap::setName(this->getName() + "_clap_name");
    this->setName("unkown");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(30);
    cout << "[DIAMONDTRAP] " << this->getName() << " constructor was called." << endl;
}

DiamondTrap::DiamondTrap (string name) {
    this->setName(name);
    ClapTrap::setName(name + "_clap_name");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(30);
    cout << "[DIAMONDTRAP] " << this->getName() << " constructor was called." << endl;
}

DiamondTrap::DiamondTrap (const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {}

DiamondTrap::~DiamondTrap() {
    cout << "[DIAMONDTRAP] " << this->getName() << " destructor was called." << endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        FragTrap::operator=(other);
    }
    return *this;
}

/* Methods */

void DiamondTrap::attack(const string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    cout << "Say my name... -" << this->getName() << " also called by -" << ClapTrap::getName() << "." << endl;
}

/* Getters and setters */

string DiamondTrap::getName(void) {
    return this->name;
}

void DiamondTrap::setName(string name) {
    this->name = name;
}
