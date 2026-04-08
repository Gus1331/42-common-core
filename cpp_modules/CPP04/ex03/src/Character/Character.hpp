#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include <iostream>
#include "AMateria/AMateria.hpp"

using std::string;
using std::cout;
using std::endl;

class Character : public ICharacter
{
    private:
        AMateria *inventory[4];
        string name;

    public:
        /* Constructors */
        Character();
        Character(string const & name);
        Character(const Character &other);
        ~Character();

        Character &operator=(const Character &other);
        
        /* Methods */
        void use(int idx, ICharacter& target);
        void equip(AMateria* m);
        void unequip(int idx);

        /* Getters and Setters */
        string const & getName() const;
        void setName(string name);
};

#endif
