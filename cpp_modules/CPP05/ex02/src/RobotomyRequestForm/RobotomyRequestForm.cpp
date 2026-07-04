#include "RobotomyRequestForm/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("unkown") {
}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm", 72, 45), target(target){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45), target(other.getTarget()) {
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other) {
    if (this != &other) {
        this->setIsSigned(other.getIsSigned());
        this->target = other.getTarget();
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

/* Methods */

static int robotomized = -1;
void RobotomyRequestForm::execute(Bureaucrat const &executor)const {
    if (executor.getGrade() > this->getGradeToExecute())
        throw (AForm::GradeTooLowException());
	else if (!this->getIsSigned())
        throw (AForm::NotSignedException());
    
    robotomized++;
	if (robotomized % 2 == 0)
		cout << "***drilling noises*** " << this->getTarget() << " has been robotomized." << endl;
	else
		cout << "robotomy failed." << endl;
}

string RobotomyRequestForm::getTarget() const {
    return this->target;
}
