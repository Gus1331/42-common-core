
#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include "AForm/AForm.hpp"
#include <fstream>

using std::ofstream;

class AForm;

class PresidentialPardonForm : public AForm {
    private:
        string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm &other);
        PresidentialPardonForm(string target);
        PresidentialPardonForm&operator=(PresidentialPardonForm &other);

        ~PresidentialPardonForm();

        /* Methods */
        void execute(Bureaucrat const &executor)const;

        string getTarget() const;
};


#endif