
#include "Data/Data.hpp"

Data::Data() : user("Anonimous USer"), pass(""), banned(true) {}

Data::Data(string user, string pass) : user(user), pass(pass), banned(false) {}

Data::Data(Data &other) {
    this->user = other.user;
    this->pass = other.pass;
    this->banned = other.banned;
}

Data &Data::operator=(Data &other) {
    if (this != &other) {
        this->user = other.user;
        this->pass = other.pass;
        this->banned = other.banned;
    }
    return *this;
}

Data::~Data() {}

/* Methods */
void Data::login() {
    if (!this->banned)
        cout << this->getUser() << " has logged in." << endl;
}

void Data::ban() {
    this->banned = true;
}

/* Getters & Setters*/

string Data::getUser() {
    return this->user;
}

string Data::getPass() {
    return this->pass;
}

bool Data::getBanned() {
    return this->banned;
}


void Data::setUser(string user) {
    this->user = user;
}

void Data::setPass(string pass) {
    this->pass = pass;
}

