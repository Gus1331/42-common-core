#include "ClapTrap/ClapTrap.hpp"
#include "ScavTrap/ScavTrap.hpp"
#include "FragTrap/FragTrap.hpp"

int main(void)
{
     FragTrap *fragtrap = new FragTrap("FragTrap");

     fragtrap->attack("Monster");
     fragtrap->attack("Zombie");
     fragtrap->takeDamage(1);
     fragtrap->beRepaired(500);
     fragtrap->highFiveGuys();
     fragtrap->takeDamage(1000);
     fragtrap->highFiveGuys();

     cout << endl;
     delete fragtrap;
}
