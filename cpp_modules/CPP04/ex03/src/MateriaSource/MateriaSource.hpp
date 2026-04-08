#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

#include <string>
#include <iostream>
#include "IMateriaSource/IMateriaSource.hpp"

using std::string;
using std::cout;
using std::endl;

class MateriaSource : public IMateriaSource
{
    private:
        string name;
        AMateria *learned[4];

    public:
        /* Constructors */
        MateriaSource();
        MateriaSource(string const & name);
        MateriaSource(const MateriaSource &other);
        ~MateriaSource();

        MateriaSource &operator=(const MateriaSource &other);
        
        /* Methods */
        void learnMateria(AMateria *m);
        AMateria* createMateria(string const & type);
};

#endif
