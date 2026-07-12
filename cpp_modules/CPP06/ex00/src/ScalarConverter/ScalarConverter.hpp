

#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

#include <iostream>

using std::string;
using std::cout;
using std::endl;

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


