
#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Animal {
    private:
        string type;
    public:
        /* Constructors */
        Animal();
        Animal(string type);
        Animal(const Animal &other);
        ~Animal();

        Animal &operator=(const Animal &other);

        /* Methods */

        virtual void makeSound(void);

        /* Getters and setters */
        string getType();
        void setType(string type);
};

#endif