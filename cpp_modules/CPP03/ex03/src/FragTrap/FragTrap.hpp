#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include <string>
#include <iostream>

#include "ClapTrap/ClapTrap.hpp"

#pragma once
class ClapTrap;

using std::string;
using std::cout;
using std::endl;

class FragTrap: public virtual ClapTrap {
    public:
        /* Constructors */
        FragTrap();
        FragTrap(string name);
        FragTrap(const FragTrap &other);
        ~FragTrap(void);

        FragTrap &operator=(const FragTrap &other);

        /* Methods */
        void highFiveGuys(void);
};

#endif
