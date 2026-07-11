#include "Bureaucrat/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unkown"), grade (1) {
}

Bureaucrat::Bureaucrat(string name, int grade) : name(name){
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.name) {
    this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

/* Methods */

void Bureaucrat::increment() {
    if (this->grade == 1) throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement() {
    if (this->grade == 150) throw GradeTooLowException();
    this->grade++;
}

/* Getters & Setters */

string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::setGrade(int grade) {
    this->grade = grade;
}

/* Exceptions */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!!!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!!!\n";
}

/* Output redirect */
ostream &operator<<(ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() <<"." << endl;
    return os;
}
