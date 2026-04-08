# ifndef __DOG_H__
# define __DOG_H__

#include "Animal/Animal.hpp"

class Dog : public Animal
{
    public:
        /* Constructors */
        Dog();
        Dog(string type);
        Dog(const Dog &other);
        ~Dog();

        Dog &operator=(const Dog &other);

        /* Methods */
        void makeSound(void) const;
};

#endif
