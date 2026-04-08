
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
        virtual ~Animal();

        Animal &operator=(const Animal &other);

        /* Methods */
        virtual void makeSound(void) const;

        /* Getters and setters */
        string getType() const;
        void setType(string type);
};

#endif