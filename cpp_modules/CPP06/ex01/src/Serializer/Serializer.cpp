
#include "Serializer/Serializer.hpp"

Serializer::Serializer() {
}

//Serializer::Serializer(params) {}

Serializer::Serializer(Serializer &other){
    (void)other;
    //this->params = other.params;
}

Serializer &Serializer::operator=(Serializer &other) {
    if (this != &other) {
        (void)other;
        //this->params = other.params;
    }
    return *this;
}

Serializer::~Serializer() {
}

/* Methods */

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

