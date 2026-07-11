

#ifndef __INTERN_H__
#define __INTERN_H__

#include "AForm/AForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"

class AForm;

class Intern {
    private:
        static AForm *makePresidentialPardonForm(string target);
        static AForm *makeRobotomyRequestForm(string target);
        static AForm *makeShrubberyCreationForm(string target);
    public:
        Intern();
        Intern(Intern &other);
        Intern&operator=(Intern &other);

        ~Intern();

        /* Methods */
        AForm *makeForm(string formName, string target);
        /* Getters & Setters*/
};

#endif


