#ifndef __ICE_H__
#define __ICE_H__

#include <string>
#include <iostream>
#include "AMateria/AMateria.hpp"

using std::string;
using std::cout;
using std::endl;

class Ice : public AMateria
{
    public:
        /* Constructors */
        Ice();
        Ice(string const & type);
        ~Ice();

        Ice &operator=(const Ice &other);
        
        /* Methods */
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
