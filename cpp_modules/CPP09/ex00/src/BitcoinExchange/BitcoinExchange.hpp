

#ifndef __BITCOINEXCHANGE_H__
#define __BITCOINEXCHANGE_H__

#include <iostream>
#include <string>
#include <exception>

using std::string;

class BitcoinExchange {
    private:
        string date;
        float value;

        BitcoinExchange();

    public:
        BitcoinExchange(string date, float val);
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange&operator=(BitcoinExchange &other);
        bool operator<(const BitcoinExchange& other) const;

        string getDate() const;
        float getValue()const;

        ~BitcoinExchange();

        class InvalidDate : public std::exception {
            public:
                virtual const char *what() const throw() { return "Invalid date format! => use: YYYY-MM-DD"; }
        };

        class InvalidValue : public std::exception {
            public:
                virtual const char *what() const throw() { return "Invalid value format!"; }
        };

        class BadFormat : public std::exception {
            public:
                virtual const char *what() const throw() { return "Invalid format! usage: YYYY-MM-DD | XX.XX"; }
        };
};

#endif


