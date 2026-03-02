
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Zombie {
    private:
        string name;
    public:
        Zombie();
        Zombie(string name);
        Zombie(const Zombie& other);

        Zombie& operator=(const Zombie& other);

        ~Zombie();

        void announce (void);
        string getName() const;
        void setName(const string &name_);
};

Zombie* zombieHorde(int N, std::string name);

#endif
