#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include <string>
#include <iostream>

#include "FragTrap/FragTrap.hpp"
#include "ScavTrap/ScavTrap.hpp"

#pragma once
class DiamondTrap;

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        string name;
    public:
        /* Constructors */
        DiamondTrap();
        DiamondTrap(string name);
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap(void);

        DiamondTrap &operator=(const DiamondTrap &other);
 
        /* Methods */
        void attack(const string &target);
        void whoAmI(void);

        /* Getters and setters */
        string getName(void);
        void setName(string name);
};

#endif
