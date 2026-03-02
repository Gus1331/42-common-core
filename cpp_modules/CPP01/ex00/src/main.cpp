#include "Zombie.hpp"

int main (void) {
    Zombie *z = newZombie("Al-an the architect");
    z->announce();
    delete z;

    randomChump("Loki the giant");
}
