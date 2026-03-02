
#include "Zombie.hpp"

Zombie::Zombie() : name("Zombie") {}

Zombie::Zombie(string name) : name(name) {}

Zombie::Zombie(const Zombie& other) {
    *this = other;
}

Zombie& Zombie::operator=(const Zombie& other) {
    if (this != &other) {
        this->name = other.name;
    }
    return *this;
}

Zombie::~Zombie() {}

void Zombie::announce (void){
    cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

string Zombie::getName() const { return name; }
void Zombie::setName(const string &name_) { this->name = name_; }
