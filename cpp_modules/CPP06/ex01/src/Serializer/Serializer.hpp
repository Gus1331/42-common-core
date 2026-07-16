

#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include "Data/Data.hpp"
#include <stdint.h>

class Data;

class Serializer {
    private:
        Serializer();
        Serializer(Serializer &other);
        Serializer&operator=(Serializer &other);
        ~Serializer();

    public:
        /* Methods */
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif


