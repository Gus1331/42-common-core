
#include "Intern/Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern &other){
    (void)other;
}

Intern &Intern::operator=(Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

/* Methods */
AForm *Intern::makePresidentialPardonForm(string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(string target) {
    return new ShrubberyCreationForm(target);
}

AForm * Intern::makeForm(string formName, string target) {
    typedef AForm* (*Maker)(std::string);

    Maker FormsPointer[3];
    
    FormsPointer[0] = &makePresidentialPardonForm;
    FormsPointer[1] = &makeRobotomyRequestForm;
    FormsPointer[2] = &makeShrubberyCreationForm;

    string FormsName[3];

    FormsName[0] = "presidential pardon";
    FormsName[1] = "robotomy request";
    FormsName[2] = "shrubbery creation";

    for(int i = 0; i < 3; i++) {
        if (formName == FormsName[i])
            return FormsPointer[i](target);
    }
    cout << "Intern could'nt understand your " << formName << " request." << endl;
    return NULL;
}



/* Getters & Setters*/


