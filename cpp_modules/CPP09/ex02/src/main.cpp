#include "PmergeMe/PmergeMe.hpp"

#include <iostream>
#include <string.h>


int main (int argc, char **argv) {
    if (argc <= 2) {
        cout << "Bad usage!" << endl;
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) > 10) {
                cout << "Bad input" << endl;
                return 1;
        }
        for (size_t j = 0; j < strlen(argv[i]); j++) {
            if (argv[i][j] < '0' || argv[i][j] > '9') {
                cout << "Bad input" << endl;
                return 1;
            }
        }
    }

    PmergeMe obj(argc, argv);



    return 0;
}
