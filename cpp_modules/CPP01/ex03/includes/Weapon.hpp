
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Weapon {
    private:
        string type;

    public:
        Weapon ();
        Weapon(string type);

        string getType();
        void setType(string type);
};

#endif
