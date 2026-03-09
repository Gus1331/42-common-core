#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>
#include <iostream>

#pragma once
class ClapTrap;

using std::string;
using std::cout;
using std::endl;

class ClapTrap {
    private:
        string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

    public:
        /* Constructors */
        ClapTrap();
        ClapTrap(string name);
        ClapTrap(const ClapTrap &other);
        ~ClapTrap(void);

        ClapTrap &operator=(const ClapTrap &other);

        /* Methods */
        void attack(const string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        /* Getters and setters */
        string getName(void);
        unsigned int getHitPoints(void);
        unsigned int getEnergyPoints(void);
        unsigned int getAttackDamage(void);
        void setName(string name);
        void setHitPoints(unsigned int hitPoints);
        void setEnergyPoints(unsigned int energyPoints);
        void setAttackDamage(unsigned int attackDamage);
};

#endif
