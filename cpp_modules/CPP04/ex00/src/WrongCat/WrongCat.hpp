#include "WrongAnimal/WrongAnimal.hpp"

#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

class WrongCat : public WrongAnimal
{
    public:
        /* Constructors */
        WrongCat();
        WrongCat(string type);
        WrongCat(const WrongCat &other);
        ~WrongCat();

        WrongCat &operator=(const WrongCat &other);

        /* Methods */
        void makeSound(void) const;
};

#endif
