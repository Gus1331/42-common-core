
#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include "AForm/AForm.hpp"
#include <fstream>

using std::ofstream;

class AForm;

class ShrubberyCreationForm : public AForm {
    private:
        string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm &other);
        ShrubberyCreationForm(string target);
        ShrubberyCreationForm&operator=(ShrubberyCreationForm &other);

        ~ShrubberyCreationForm();

        /* Methods */
        void execute(Bureaucrat const &executor)const;

        string getTarget();
};


#endif