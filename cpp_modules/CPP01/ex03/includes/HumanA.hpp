
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <iostream>
#include <string>

#pragma once
class Weapon;

using std::string;
using std::cout;
using std::endl;

class HumanA {
    private:
        string name;
        Weapon &weapon;

    public:
        HumanA(string name, Weapon& weapon);

        void attack(void);
        
        string getName() const;
        void setName(const string &name_);

        Weapon getWeapon();
        void setWeapon(Weapon weapon_);
};

#endif
