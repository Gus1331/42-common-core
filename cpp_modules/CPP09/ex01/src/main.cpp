#include "RPN/RPN.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main (int argc, char **argv) {
    if (argc != 2) {
        cout << "Bad usage!" << endl;
        return 1;
    }
    try {
        RPN rpn(argv[1]);
        cout << rpn.solve() << endl;
    } catch (std::exception &e) {
        cout << "Error" << endl;
    }
    return 0;
}
