#include "ScavTrap.hpp"

/* Constructors */
ScavTrap::ScavTrap() {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    cout << "[SCAVTRAP] " << this->getName() << " constructor was called." << endl;
}

ScavTrap::ScavTrap (string name) {
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    cout << "[SCAVTRAP] " << this->getName() << " constructor was called." << endl;
}

ScavTrap::ScavTrap (const ScavTrap &other) : ClapTrap(other) {}

ScavTrap::~ScavTrap() {
    cout << "[SCAVTRAP] " << this->getName() << " destructor was called." << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

/* Methods */
void ScavTrap::guardGate(void) {
    cout << "> " << this->getName();
    if (this->getHitPoints() == 0) {
        cout << " is dead and couldn't guard the gate." << endl;
        return;
    }
    else if (this->getEnergyPoints() == 0) {
        cout << " has no energy and couldn't guard the gate." << endl;
        return;
    }
    cout << " is now guarding the gate." << endl;
}
