#ifndef __CAT_H__
#define __CAT_H__

#include "Animal/Animal.hpp"
#include "Brain/Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        /* Constructors */
        Cat();
        Cat(string type);
        Cat(const Cat &other);
        ~Cat();

        Cat &operator=(const Cat &other);

        /* Methods */
        void makeSound(void) const;

        /* Getters and setters */
        Brain &getBrain(void);
};

#endif
