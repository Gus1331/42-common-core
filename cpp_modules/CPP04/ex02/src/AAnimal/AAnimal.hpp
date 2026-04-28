
#ifndef __AANIMAL_H__
#define __AANIMAL_H__

#include <iostream>
#include <string>

#include "Brain/Brain.hpp"

using std::cout;
using std::endl;
using std::string;

class AAnimal {
   private:
        string type;
    public:
        /* Constructors */
        AAnimal();
        AAnimal(string type);
        AAnimal(const AAnimal &other);
        virtual ~AAnimal();

        AAnimal &operator=(const AAnimal &other);

        /* Methods */
        virtual void makeSound(void) const = 0;

        /* Getters and setters */
        string getType() const;
        void setType(string type);
        virtual Brain &getBrain() const;
};

#endif