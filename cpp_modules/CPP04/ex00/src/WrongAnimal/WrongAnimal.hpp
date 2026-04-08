
#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class WrongAnimal {
    private:
        string type;
    public:
        /* Constructors */
        WrongAnimal();
        WrongAnimal(string type);
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &other);

        /* Methods */
        virtual void makeSound(void) const;

        /* Getters and setters */
        string getType() const;
        void setType(string type);
};

#endif