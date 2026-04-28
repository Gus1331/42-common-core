#ifndef __CAT_H__
#define __CAT_H__

#include "AAnimal/AAnimal.hpp"
#include "Brain/Brain.hpp"

class Cat : public AAnimal
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
        Brain &getBrain(void) const;
};

#endif
