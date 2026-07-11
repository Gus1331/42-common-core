#include "AForm/AForm.hpp"

AForm::AForm() : name("Generic Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
}

AForm::AForm(string name, int gradeToSign, int gradeToExecute) :
    name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(AForm &other) :
name(other.getName()), isSigned(other.getIsSigned()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute()) {

}

AForm& AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->isSigned = other.getIsSigned();
    }
    return *this;
}

AForm::~AForm(){
}

/* Methods */

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->isSigned = true;
}


/* Getters */

string AForm::getName() const {
    return this->name;
}

bool AForm::getIsSigned() const{
    return this->isSigned;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

void AForm::setIsSigned(bool value) {
    this->isSigned = value;
}

/* Exceptions */

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!!!\n";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!!!\n";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed!!!\n";
}

/* Output redirect */

ostream &operator<<(ostream &os, AForm const &obj) {
    os << obj.getName() << " status: " << (obj.getIsSigned() ? "true" : "false")
        << ", grade required to sign:" << obj.getGradeToSign()
        << ", , grade required to execute:" << obj.getGradeToExecute() << endl;
    return os;
}