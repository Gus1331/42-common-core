#include "Animal/Animal.hpp"

#ifndef __CAT_H__
#define __CAT_H__

class Cat : public Animal
{
    public:
        /* Constructors */
        Cat();
        Cat(string type);
        Cat(const Cat &other);
        ~Cat();

        Cat &operator=(const Cat &other);

        /* Methods */
        void makeSound(void) const;
};

#endif
