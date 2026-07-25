#include "BitcoinExchange/BitcoinExchange.hpp"

#include <fstream>
#include <set>
#include <cstdlib>

using std::cout;
using std::endl;
using std::set;

int read_csv(set<BitcoinExchange> btcSet) {
    std::ifstream f("data.csv");

    if (!f.is_open()) {
        cout << "Error opening the file!";
        return 0;
    }

    std::string s;

    while (std::getline(f, s)) {
        try {
            btcSet.insert(BitcoinExchange(
                    s.substr(0, s.find(',')),
                    atof(s.substr(s.find(',') + 1, s.length() -1).c_str())));
            } catch (std::exception &e) {
                cout << e.what() << " on: " << s << endl;
            }
    }

    f.close();
    return 0;
}

int main () {
    set<BitcoinExchange> btcSet;

    if (read_csv(btcSet) > 0) return 1;
    return 0;
}
