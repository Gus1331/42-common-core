
#include "AMateria/AMateria.hpp"
#include "IMateriaSource/IMateriaSource.hpp"
#include "MateriaSource/MateriaSource.hpp"
#include "Ice/Ice.hpp"
#include "Cure/Cure.hpp"
#include "Character/Character.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    cout << endl << endl;

    IMateriaSource* materiaSrc = new MateriaSource();
    materiaSrc->learnMateria(new Ice());
    materiaSrc->learnMateria(new Cure());
    ICharacter* character = new Character("a cool character");
    AMateria* materia;
    materia = materiaSrc->createMateria("ice");
    character->equip(materia);
    materia = materiaSrc->createMateria("cure");
    character->equip(materia);
    materia = materiaSrc->createMateria("ice");
    character->equip(materia);
    materia = materiaSrc->createMateria("ice");
    character->equip(materia);
    ICharacter* dummy = new Character("dummy");
    character->use(0, *dummy);
    character->use(1, *dummy);
    character->use(2, *dummy);
    character->use(3, *dummy);
    delete dummy;
    delete character;
    delete materiaSrc;
}
