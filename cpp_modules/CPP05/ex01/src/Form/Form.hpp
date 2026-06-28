

#ifndef __FORM_H__
#define __FORM_H__


#include <iostream>
#include <string.h>
#include "Bureaucrat/Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Bureaucrat;

class Form {
    private:
        const string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        Form();
        Form(string name, int gradeToSign, int gradeToExecute);
        Form(Form& other);
        Form& operator=(const Form &other);
        ~Form();

        /* Methods */
        void beSigned(const Bureaucrat& b);

        /* Getters */
        string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        /* Exceptions */
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

ostream &operator<<(ostream &os, const Form& obj);

#endif