#include "ClapTrap.hpp"

/* Constructors */

ClapTrap::ClapTrap() {
    name = "unkown";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    cout << "[CLAPTRAP] " << this->getName() << " constructor was called." << endl;
}

ClapTrap::ClapTrap(string name) {
    this->name = name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    cout << "[CLAPTRAP] " << this->getName() << " constructor was called." << endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
}

ClapTrap::~ClapTrap() {
    cout << "[CLAPTRAP] " << this->getName() << " destructor was called." << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->setName(other.name);
        this->setHitPoints(other.hitPoints);
        this->setEnergyPoints(other.energyPoints);
        this->setAttackDamage(other.attackDamage);
    }
    return *this;
}

/* Methods */

void ClapTrap::attack(const string &target) {
    cout << "> " << this->getName() << " ";

    if (this->getHitPoints() == 0) {
        cout << "is dead and couldn't attack " << target  << "!" << endl;
        return;
    }
    else if (this->getEnergyPoints() == 0) {
        cout << "hadn't enough energy to attack " << target  << "!" << endl;
        return;
    }
    
    cout << "attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount) {
    cout << "> " << this->getName() << " ";

    if (this->getHitPoints() == 0) {
        cout << "is already dead, and it was coldly kicked!" << endl;
        return;
    }

    cout << "took " << amount << " points of damage";

    if (amount >= this->getHitPoints()) {
        cout << " and died!" << endl;
        this->setHitPoints(0);
    }
    else {
        cout << "!" << endl;
        this->setHitPoints(this->getHitPoints() - amount);
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    cout << "> " << this->getName() << " ";

    if (this->getHitPoints() == 0) {
        cout << "is dead and couldn't repair itself!" << endl;
        return;
    }
    else if (this->getEnergyPoints() == 0) {
        cout << "hadn't enough energy to repair itself! " << endl;
        return;
    }

    cout << "repaired itself gaining " << amount << " hit points!" << endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
    this->setHitPoints(this->getHitPoints() + amount);
}

/* Getters and setters */

string ClapTrap::getName(void) {return this->name;}
unsigned int ClapTrap::getHitPoints(void) {return this->hitPoints;}
unsigned int ClapTrap::getEnergyPoints(void) {return this->energyPoints;}
unsigned int ClapTrap::getAttackDamage(void) {return this->attackDamage;}
void ClapTrap::setName(string name) {this->name = name;}
void ClapTrap::setHitPoints(unsigned int hitPoints) {this->hitPoints = hitPoints;}
void ClapTrap::setEnergyPoints(unsigned int energyPoints) {this->energyPoints = energyPoints;}
void ClapTrap::setAttackDamage(unsigned int attackDamage) {this->attackDamage = attackDamage;}
