

#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <limits>

using std::string;
using std::cout;
using std::endl;

int handleType(const string literal);
void handleSpecial(const string literal);
void handleChar(const char c);
void handleInt(const string literal);
void handleFloat(const string literal);
void handleDouble(const string literal);

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter &other);
        ScalarConverter&operator=(ScalarConverter &other);
        ~ScalarConverter();
    public:
        /* Methods */
        static void convert(string toConvert);
};

#endif


