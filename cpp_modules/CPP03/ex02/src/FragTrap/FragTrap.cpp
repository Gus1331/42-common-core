#include "FragTrap.hpp"

/* Constructors */

FragTrap::FragTrap() {
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    cout << "[FRAGTRAP] " << this->getName() << " constructor was called." << endl;
}

FragTrap::FragTrap (string name) {
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    cout << "[FRAGTRAP] " << this->getName() << " constructor was called." << endl;
}

FragTrap::FragTrap (const FragTrap &other) : ClapTrap(other) {}

FragTrap::~FragTrap() {
    cout << "[FragTrap] " << this->getName() << " destructor was called." << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

/* Methods */

void FragTrap::highFiveGuys(void) {
    cout << "> " << this->getName();
    if (this->getHitPoints() == 0) {
        cout << " is dead and couldn't request a high-five." << endl;
        return;
    }
    else if (this->getEnergyPoints() == 0) {
        cout << " has no energy and couldn't request a high-five." << endl;
        return;
    }
    cout << " high-fived!" << endl;
}
