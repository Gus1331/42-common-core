#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__


#include <iostream>
#include <string.h>
#include "AForm/AForm.hpp"
#include <exception>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class AForm;

class Bureaucrat {
    private:
        const string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat &other);
        Bureaucrat(string name, int grade);
        Bureaucrat&operator=(Bureaucrat &other);

        ~Bureaucrat();

        /* Methods */
        void increment();
        void decrement();
        void signForm(AForm &form);
        void executeForm(AForm const& form) const;

        /* Getters */
        string getName() const;
        int getGrade() const;

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

ostream &operator<<(std::ostream& os, const Bureaucrat &obj);

#endif