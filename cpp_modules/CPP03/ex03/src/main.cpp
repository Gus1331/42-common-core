#include "DiamondTrap/DiamondTrap.hpp"

int main(void)
{
     DiamondTrap *dTrap = new DiamondTrap("Heisenberg");

     dTrap->attack("Jessie");
     dTrap->attack("Gus");
     dTrap->takeDamage(1);
     dTrap->beRepaired(500);
     dTrap->guardGate();
     dTrap->highFiveGuys();
     dTrap->takeDamage(1000);
     dTrap->highFiveGuys();
     dTrap->whoAmI();

     cout << endl;
     delete dTrap;
}
