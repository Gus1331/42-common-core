#include "Brain/Brain.hpp"

/* Constructors */

Brain::Brain() : ideasCount(0) {
    cout << "<Brain constructor>" << endl;
}

Brain::Brain(const Brain &other) {
    cout << "<Brain constructor>" << endl;
    *this = other;
};

Brain::~Brain() {
    cout << "<Brain destructor>" << endl;
};

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        this->ideasCount = other.ideasCount;
        for (int i = 0; i < other.ideasCount; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
};

/* Methods */

void Brain::newIdea(string newIdea) {
    if (getIdeasCount() >= 99) {
        cout << "BURNOUT!" << endl;
        return;
    }
    this->ideas[getIdeasCount()] = newIdea;
    setIdeasCount(getIdeasCount() + 1);
};

/* Getters and Setters */

string *Brain::getIdeas(void)
{
    return &(this->ideas[0]);
}

void Brain::setIdeas(int ideas[100]) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = ideas[i];
    }
}

int Brain::getIdeasCount(void) {
    return this->ideasCount;
}

void Brain::setIdeasCount(int ideasCount) {
    this->ideasCount = ideasCount;
}
