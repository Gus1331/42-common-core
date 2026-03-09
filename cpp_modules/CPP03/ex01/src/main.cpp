#include "ClapTrap/ClapTrap.hpp"
#include "ScavTrap/ScavTrap.hpp"

int main(void)
{
     ScavTrap *sphinx = new ScavTrap("Sphinx");

     sphinx->attack("Human");
     sphinx->attack("Human");
     sphinx->takeDamage(1);
     sphinx->beRepaired(500);
     sphinx->guardGate();
     sphinx->takeDamage(1000);
     sphinx->guardGate();

     cout << endl;
     delete sphinx;
}
