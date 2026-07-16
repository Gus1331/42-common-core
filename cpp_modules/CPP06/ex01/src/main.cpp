# include "Serializer/Serializer.hpp"

int main() {
    Data *u1 = new Data("gus", "judasPriest");
    Data *u2 = new Data("sug", "motleyCrüe");
    Data *u3 = new Data(*u1);
    Data *u4 = new Data();

    *u4 = *u2;

    u3->setPass("AC/DC");
    u4->setPass("Guns N Roses");

    u3->ban();
    u4->ban();

    uintptr_t s1 = Serializer::serialize(u1);
    uintptr_t s2 = Serializer::serialize(u2);
    uintptr_t s3 = Serializer::serialize(u3);
    uintptr_t s4 = Serializer::serialize(u4);

    Data *p1 = Serializer::deserialize(s1);
    Data *p2 = Serializer::deserialize(s2);
    Data *p3 = Serializer::deserialize(s3);
    Data *p4 = Serializer::deserialize(s4);

    cout << "{user: " << p1->getUser() <<"; pass: " << p1->getPass() <<";\tbanned: '"<< p1->getBanned() << "'}" << endl;
    cout << "{user: " << p2->getUser() <<"; pass: " << p2->getPass() <<";\tbanned: '"<< p2->getBanned() << "'}" << endl;
    cout << "{user: " << p3->getUser() <<"; pass: " << p3->getPass() <<";\tbanned: '"<< p3->getBanned() << "'}" << endl;
    cout << "{user: " << p4->getUser() <<"; pass: " << p4->getPass() <<";\tbanned: '"<< p4->getBanned() << "'}" << endl;

    delete(u1);
    delete(u2);
    delete(u3);
    return 0;
}