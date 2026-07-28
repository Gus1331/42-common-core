
#include "RPN/RPN.hpp"

RPN::RPN() {
}

RPN::RPN(string RPN) {
    string fls(RPN);
    while(fls.find(' ') != fls.npos)
        fls.erase(fls.find(' '), 1);
    for (size_t i = 0; i < fls.size(); i++) {
        if ((fls.at(i) < '0' || fls.at(i) > '9')
            && fls.at(i) != '+'
            && fls.at(i) != '-'
            && fls.at(i) != '*'
            && fls.at(i) != '/')
                throw BadFormat();
    }

    this->fs = fls;
}

RPN::RPN(RPN &other){
    this->fs = other.fs;
}

RPN &RPN::operator=(RPN &other) {
    if (this != &other) {
        this->fs = other.fs;
    }
    return *this;
}

RPN::~RPN() {
}

/* Methods */
int RPN::solve() {
    stack<int> s;

    for (size_t i = 0; i < this->fs.size(); i++) {
        if (fs.at(i) >= '0' && fs.at(i) <= '9')
            s.push(fs.at(i) - '0');
        else {
            if (s.size() < 2) throw BadFormat();
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();

            switch (fs.at(i)) {
                case '+':
                    s.push(n2 + n1);
                    break;
                case '-':
                    s.push(n2 - n1);
                    break;
                case '*':
                    s.push(n2 * n1);
                    break;
                case '/':
                    if (n1 == 0) throw BadFormat();
                    s.push(n2 / n1);
                    break;
                default:
                    throw BadFormat();
            }
        }
    }

    if (s.size() > 1) throw BadFormat();
    return s.top();
}

