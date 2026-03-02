
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <iostream>
#include <string>

#pragma once
class Weapon;

using std::string;
using std::cout;
using std::endl;

class HumanB {
    private:
        string name;
        Weapon *weapon;
        
    public:
        HumanB();
        HumanB(string name);

        void attack(void);
        
        string getName() const;
        void setName(const string &name_);

        Weapon getWeapon() const;
        void setWeapon(Weapon& weapon_);
};

#endif
