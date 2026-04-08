#include "Cat/Cat.hpp"
#include "Dog/Dog.hpp"

int main() {
    Animal *animals[10];
    for (int i = 0; i < 10; i++) {
        if (i < 5)
            animals[i] = new Cat;
        else
            animals[i] = new Dog;
    }

    for (int i = 0; i < 10; i++) {
        if (i < 5)
            ((Cat *)animals[i])->getBrain().newIdea("catnip");
        else
            ((Dog *)animals[i])->getBrain().newIdea("ride");

        cout << "animal " << i + 1 << ": 💭 " << *((Cat *)animals[i])->getBrain().getIdeas() << " 💬 ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }
    return 0;
}
