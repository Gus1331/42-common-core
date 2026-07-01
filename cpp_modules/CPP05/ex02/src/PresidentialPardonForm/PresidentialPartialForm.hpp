
#ifndef __PRESIDENTIALPARTIALFORM_H__
#define __PRESIDENTIALPARTIALFORM_H__

#include "AForm/AForm.hpp"
#include <fstream>

using std::ofstream;

class AForm;

class PresidentialPartialForm : public AForm {
    private:
    public:
        PresidentialPartialForm();
        PresidentialPartialForm(PresidentialPartialForm &other);
        PresidentialPartialForm(string target);
        PresidentialPartialForm&operator=(PresidentialPartialForm &other);

        ~PresidentialPartialForm();

        /* Methods */
        void beSigned(const Bureaucrat& b);
};


#endif