#ifndef __IMATERIASOURCE_H__
#define __IMATERIASOURCE_H__

#include <string>
#include "AMateria/AMateria.hpp"

using std::string;

class IMateriaSource
{
    public:
        virtual ~IMateriaSource();
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(string const & type) = 0;
};

#endif
