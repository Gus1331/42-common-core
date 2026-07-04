#include "PresidentialPardonForm/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("RobotomyRequestForm", 25, 5), target("unkown") {
}

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("RobotomyRequestForm", 25, 5), target(target)  {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm("RobotomyRequestForm", 25, 5), target(other.getTarget())  {
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other) {
    if (this != &other) {
        this->setIsSigned(other.getIsSigned());
        this->target = other.getTarget();
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

/* Methods */

void PresidentialPardonForm::execute(Bureaucrat const &executor)const {
    if (executor.getGrade() > this->getGradeToExecute())
        throw (AForm::GradeTooLowException());
	else if (!this->getIsSigned())
        throw (AForm::NotSignedException());
    
    cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << endl;
}

string PresidentialPardonForm::getTarget() const {
    return this->target;
}
