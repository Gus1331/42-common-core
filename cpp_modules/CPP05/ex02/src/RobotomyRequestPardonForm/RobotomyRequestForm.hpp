
#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "AForm/AForm.hpp"
#include <fstream>

using std::ofstream;

class AForm;

class RobotomyRequestForm : public AForm {
    private:
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm &other);
        RobotomyRequestForm(string target);
        RobotomyRequestForm&operator=(RobotomyRequestForm &other);

        ~RobotomyRequestForm();

        /* Methods */
        void beSigned(const Bureaucrat& b);
};


#endif