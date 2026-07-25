
#include "BitcoinExchange/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(string date, float val) {
    if (date.length() != 10) throw InvalidDate();
    if (val < 0) throw InvalidValue();

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date.at(i) != '-') throw InvalidDate();
            continue;
        }
        else if (date.at(i) < '0' || date.at(i) > '9')
            throw InvalidDate();
    }

    if (date.at(5) > '1' || (date.at(5) == '1' && date.at(6) > '2')) throw InvalidDate();
    if (date.at(5) == '0' && date.at(6) == '0') throw InvalidDate();

    if (date.at(8) > '3' || (date.at(8) == '3' && date.at(9) > '1')) throw InvalidDate();
    if (date.at(8) == '0' && date.at(9) == '0') throw InvalidDate();

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other): date(other.date), value(other.value) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other) {
    if (this != &other) {
        this->date = other.date;
        this->value = other.value;
    }
    return *this;
}

bool BitcoinExchange::operator<(const BitcoinExchange& other) const {
    return this->date < other.date;
}

BitcoinExchange::~BitcoinExchange() {}
