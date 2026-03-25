#include "ClapTrap/ClapTrap.hpp"

int main(void)
{
     ClapTrap *zoro = new ClapTrap("Zoro");
     zoro->setAttackDamage(6000);
     zoro->setHitPoints(8000);

     cout << endl
          << "Case 1:" << endl;
     zoro->attack("XDrake");
     zoro->attack("Apoo");
     zoro->takeDamage(1000);
     zoro->beRepaired(500);
     zoro->takeDamage(1000);
     zoro->attack("Queen");
     zoro->takeDamage(2000);
     zoro->attack("King");
     zoro->takeDamage(4499);
     zoro->attack("King");

     cout << endl;
     delete zoro;

     ClapTrap *luffy = new ClapTrap("luffy");
     luffy->setAttackDamage(6000);
     luffy->setHitPoints(8000);

     cout << endl
          << "Case 2:" << endl;

     luffy->takeDamage(2000);
     luffy->attack("Kaido");
     luffy->attack("Kaido");
     luffy->attack("Kaido");
     luffy->attack("Kaido");
     luffy->attack("Kaido");
     luffy->takeDamage(2000);
     luffy->takeDamage(2000);
     luffy->attack("Kaido");
     luffy->attack("Kaido");
     luffy->takeDamage(2000);
     luffy->attack("Kaido");
     luffy->takeDamage(2000);

     cout << endl;
     delete luffy;

     ClapTrap *nika = new ClapTrap("luffy gear 5");
     nika->setAttackDamage(8000);

     cout << endl
          << "Case 3:" << endl;

     nika->beRepaired(20000);
     nika->takeDamage(2000);
     nika->attack("Kaido");
     nika->attack("Kaido");
     nika->attack("Kaido");
     nika->attack("Kaido");
     nika->attack("Kaido");
     nika->takeDamage(2000);
     nika->takeDamage(2000);
     nika->beRepaired(1000);
     nika->attack("Kaido");
     nika->attack("Kaido");
     nika->takeDamage(2000);
     nika->attack("Kaido");
     nika->attack("Kaido");
     nika->beRepaired(1000);

     cout << endl;
     delete nika;
}
