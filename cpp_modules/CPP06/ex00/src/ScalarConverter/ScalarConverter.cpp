
#include "ScalarConverter/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}


ScalarConverter::ScalarConverter(ScalarConverter &other){
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

/* Methods */
void ScalarConverter::convert(string toConvert) {
    int type = handleType(toConvert);

    switch (type) {
        case 0 :
            handleSpecial(toConvert);
            break;
        case 1 :
            handleChar(toConvert.at(0));
            break;
        case 2 :
            handleInt(toConvert);
            break;
        case 3 :
            handleFloat(toConvert);
            break;
        case 4 :
            handleDouble(toConvert);
            break;
        default :
            cout << "Impossible conversion" << endl;
    }
}

