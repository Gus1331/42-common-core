#include "Form/Form.hpp"

Form::Form() : name("Generic Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
}

Form::Form(string name, int gradeToSign, int gradeToExecute) :
    name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(Form &other) :
name(other.getName()), isSigned(other.getIsSigned()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute()) {

}

Form& Form::operator=(const Form &other) {
    if (this != &other) {
        this->isSigned = other.getIsSigned();
    }
    return *this;
}

Form::~Form(){

}

/* Methods */

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->gradeToSign) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->isSigned = true;
}

/* Getters & Setters*/

string Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const{
    return this->isSigned;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

void Form::setIsSigned(bool isSigned) {
    this->isSigned = isSigned;
}

/* Exceptions */

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!!!\n";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!!!\n";
}

/* Output redirect */

ostream &operator<<(ostream &os, Form const &obj) {
    os << obj.getName() << " status: " << (obj.getIsSigned() ? "true" : "false")
        << ", grade required to sign:" << obj.getGradeToSign()
        << ", , grade required to execute:" << obj.getGradeToExecute() << endl;
    return os;
}