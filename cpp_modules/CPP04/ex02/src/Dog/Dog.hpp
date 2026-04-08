# ifndef __DOG_H__
# define __DOG_H__

#include "AAnimal/AAnimal.hpp"
#include "Brain/Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *brain;
    public:
        /* Constructors */
        Dog();
        Dog(string type);
        Dog(const Dog &other);
        ~Dog();

        Dog &operator=(const Dog &other);

        /* Methods */
        void makeSound(void) const;

        /* Getters and setters */
        Brain &getBrain(void);
};
#endif