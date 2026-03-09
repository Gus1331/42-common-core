#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include <string>
#include <iostream>

#include "ClapTrap/ClapTrap.hpp"

#pragma once
class ScavTrap;

using std::string;
using std::cout;
using std::endl;

class ScavTrap: public ClapTrap {
    public:
        /* Constructors */
        ScavTrap();
        ScavTrap(string name);
        ScavTrap(const ScavTrap &other);
        ~ScavTrap(void);

        ScavTrap &operator=(const ScavTrap &other);

        /* Methods */
        void guardGate(void);
};

#endif
