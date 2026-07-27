#include "BitcoinExchange/BitcoinExchange.hpp"

#include <fstream>
#include <set>
#include <cstdlib>

using std::cout;
using std::endl;
using std::set;

int read_csv(set<BitcoinExchange> &btcSet) {
    std::ifstream f("data.csv");

    if (!f.is_open()) {
        cout << "Error opening .csv file!" << endl;
        return 1;
    }

    std::string s;

    if (!std::getline(f, s)) return 1; // read header first;

    while (std::getline(f, s)) {
        try {
            btcSet.insert(BitcoinExchange(
                    s.substr(0, s.find(',')),
                    atof(s.substr(s.find(',') + 1, s.length() -1).c_str())));
            } catch (std::exception &e) {
                f.close();
                cout << e.what() << " on: " << s << endl;
                return 1;
            }
    }

    f.close();
    if (btcSet.size() < 1) return 1;
    return 0;
}

int main (int argc, char **argv) {
    if (argc != 2) {
        cout << "Bad usage!" << endl;
        return 0;
    }

    set<BitcoinExchange> btcSet;

    if (read_csv(btcSet) > 0) return 1;
    
    {
        std::ifstream f(argv[1]);

        if (!f.is_open()) {
            cout << "Error opening '" << argv[1] << "' file!" << endl;
            return 1;
        }

        std::string s;

        if (!std::getline(f, s)) return 1; // header
        while (std::getline(f, s)) {
            const BitcoinExchange *match = &(*btcSet.begin());
            string date = s.substr(0, s.find('|'));
            if (date.find(' ') != date.npos)
                date.erase(date.find(' '));
            float val = atof(s.substr(s.find('|') + 1, s.length() -1).c_str());
            
            try {
                if (date.length() != 10) throw BitcoinExchange::InvalidDate();
                if (val < 0 || val > 1000) throw BitcoinExchange::InvalidValue();

                for (int i = 0; i < 10; i++) {
                    if (i == 4 || i == 7) {
                        if (date.at(i) != '-') throw BitcoinExchange::InvalidDate();
                        continue;
                    }
                    else if (date.at(i) < '0' || date.at(i) > '9')
                        throw BitcoinExchange::InvalidDate();
                }

                if (date.at(5) > '1' || (date.at(5) == '1' && date.at(6) > '2')) throw BitcoinExchange::InvalidDate();
                if (date.at(5) == '0' && date.at(6) == '0') throw BitcoinExchange::InvalidDate();

                if (date.at(8) > '3' || (date.at(8) == '3' && date.at(9) > '1')) throw BitcoinExchange::InvalidDate();
                if (date.at(8) == '0' && date.at(9) == '0') throw BitcoinExchange::InvalidDate();

                for (set<BitcoinExchange>::iterator it = btcSet.begin(); it != btcSet.end(); ++it) {
                    if ((*it).getDate() < date && (*it).getDate() > match->getDate())
                        match = &(*it);
                }

                cout << date << " => " << match->getValue() * val << endl;
            } catch (std::exception &e) {
                cout << "Error: " << e.what() << " on: " << s << endl;
            }
        }

        f.close();
    }
    return 0;
}
