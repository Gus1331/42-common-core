#include "Cat/Cat.hpp"
#include "Dog/Dog.hpp"
#include "WrongCat/WrongCat.hpp"

int main() {
    cout << "Animal x Cat x Dog" << endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "Cat is " << i->getType() << " " << std::endl;
    std::cout << "Dog is " << j->getType() << " " << std::endl;
    std::cout << endl << "Sounds:" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    cout << endl << "WrongAnimal x WrongCat" << endl;
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wi = new WrongCat();
    std::cout << wi->getType() << " " << std::endl;
    wi->makeSound();
    wmeta->makeSound();

    delete wi;
    delete wmeta;
    return 0;
}
