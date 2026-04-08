#ifndef __CURE_H__
#define __CURE_H__

#include <string>
#include <iostream>
#include "AMateria/AMateria.hpp"

using std::string;
using std::cout;
using std::endl;

class Cure : public AMateria
{
    public:
        /* Constructors */
        Cure();
        Cure(string const & type);
        ~Cure();

        Cure &operator=(const Cure &other);
        
        /* Methods */
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
