

#ifndef __RPN_H__
#define __RPN_H__

#include <stack>
#include <exception>
#include <string>

using std::stack;
using std::string;

class RPN {
    private:
        string fs;
        RPN();

    public:
        RPN(string RPN);
        RPN(RPN &other);
        RPN&operator=(RPN &other);

        ~RPN();

        /* Methods */
        int solve();

        class BadFormat : public std::exception {
            public:
                virtual const char *what() const throw() { return "Invalid RPN format! usage:"; }
        };
};

#endif


