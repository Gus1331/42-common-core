#include "Harl.hpp"

int main (int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: ./harl <LEVEL>" << endl;
        return 1;
    }
    Harl harl = Harl();

    {
        int lvl = 0;
        string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        for (int i = 0; i < 4 ;i++) {
            lvl = i;
            if (levels[i] == string(argv[1]))
                break ;
            if (i == 3)
                lvl = -1;
        }

        switch (lvl) {
            case 0 :
                cout << "[DEBUG]" << endl;
                harl.complain("DEBUG");
                cout << endl;
                /* fallthrough */
            case 1 : 
                cout << "[INFO]" << endl;
                harl.complain("INFO");
                cout << endl;
                /* fallthrough */
            case 2 :
                cout << "[WARNING]" << endl;
                harl.complain("WARNING");
                cout << endl;
                /* fallthrough */
            case 3 :
                cout << "[ERROR]" << endl;
                harl.complain("ERROR");
                cout << endl;
                break;

            default :
                cout << "no such level;" << endl;
        }

    }
}
