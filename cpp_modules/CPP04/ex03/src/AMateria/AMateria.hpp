#ifndef __AMATERIA_H__
#define __AMATERIA_H__

#include <string>
#include <iostream>
#include "ICharacter/ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;

class AMateria
{
    protected:
        string type;

    public:
        /* Constructors */
        AMateria();
        AMateria(string const &type);
        AMateria(const AMateria &other);
        virtual ~AMateria();

        AMateria &operator=(const AMateria &other);
        
        /* Methods */
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        /* Getters and setters */
        string const &getType() const;

};

#endif
