

#ifndef __AFORM_H__
#define __AFORM_H__


#include <iostream>
#include <string.h>
#include "Bureaucrat/Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Bureaucrat;

class AForm {
    private:
        const string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        AForm();
        AForm(string name, int gradeToSign, int gradeToExecute);
        AForm(AForm& other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        /* Methods */
        void virtual beSigned(const Bureaucrat& b);
        void virtual execute(Bureaucrat const &executor) const = 0;

        /* Getters */
        string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void setIsSigned(bool value);

        /* Exceptions */
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

ostream &operator<<(ostream &os, const AForm& obj);

#endif