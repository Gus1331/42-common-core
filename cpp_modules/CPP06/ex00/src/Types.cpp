
#include "ScalarConverter/ScalarConverter.hpp"

int handleType(const string literal) {
    if (literal.length() == 0) return -1;

    if (literal == "inf" || literal == "inff" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff" ||
        literal == "nan" || literal == "nanf") // checks special
        return 0;

    if (literal.length() == 1 && !(literal.at(0) >= '0' && literal.at(0) <= '9')) // checks simple char
        return 1;

    if ((literal.at(0) >= '0' && literal.at(0) <= '9') || literal.at(0) == '-' || literal.at(0) == '+') { // checks only numbers
        if (literal.length() == 1)  return 2;
        for (size_t i = 1; i < literal.length(); i++) {
            if (literal.at(i) < '0' || literal.at(i) > '9')
                break;
            if (i == literal.length() - 1) return 2;
        }
    }

    if (literal == "-." || literal == "+." ||
        literal == "+.f" || literal == "+.F"
        || literal == "-.f" || literal == "-.F") return -1; // invalid floats & doubles

    if (literal.length() >= 3){ // checks float
        int dots = 0;
        for (size_t i = 0; i < literal.length(); i++) {
            if (i == 0 && (literal.at(i) == '+' || literal.at(i) == '-')) continue;
            if ((literal.at(i) < '0' || literal.at(i) > '9') && literal.at(i) != '.' && literal.at(i) != 'f' && literal.at(i) != 'F') // invalid char
                break;
            if (literal.at(i) == '.')
                dots++; // count dots
            if (i == literal.length() - 1 && (literal.at(i) == 'F' || literal.at(i) == 'f') && dots == 1) // valid end
                return 3;
            if (literal.at(i) == 'F' || literal.at(i) == 'f') // premature end
                break;
        }
    }

    if (literal.length() >= 2){ // checks double
        int dots = 0;
        for (size_t i = 0; i < literal.length(); i++) {
            if (i == 0 && (literal.at(i) == '+' || literal.at(i) == '-')) continue;
            if ((literal.at(i) < '0' || literal.at(i) > '9') && literal.at(i) != '.') // invalid char
                break;
            if (literal.at(i) == '.')
                dots++; // count dots
            if (i == literal.length() - 1 && dots == 1) // valid end
                return 4;
        }
    }

    return -1; // fallback
}


void handleSpecial(const string literal) {
    cout << "char: impossible" << endl;
    cout << "int: impossible" << endl;

    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
        cout << "float : inff" << endl << "double: inf" << endl;
    if (literal == "-inf" || literal == "-inff")
        cout << "float : -inff" << endl << "double: -inf" << endl;
    if (literal == "nan" || literal == "nanf")
        cout << "float : nanf" << endl << "double: nan" << endl;
}


void handleChar(const char c) {
    cout << "char: ";
    if (c < ' ' || c > '~')
        cout << "Non displayable" << endl;
    else
        cout << "'" << c << "'" << endl;
    cout << "int: " << static_cast<int>(c) << endl;
    cout << "float: " << static_cast<int>(c) << ".0f" << endl;
    cout << "double: " << static_cast<int>(c) << ".0" << endl;
}

void handleInt(const string literal) {
    int n;

    std::istringstream iss(literal);

    if (!(iss >> n))
        cout << "this conversion is impossible." << endl;
    else {
        cout << "char: ";
        if (n > 127 || n < 0)
            cout << "impossible" << endl;
        else if (n < ' ' || n > '~')
            cout << "Non displayable" << endl;
        else
            cout << "'" << (char)n << "'" << endl;
        cout << "int: " << n  << endl;
        cout << "float: " << n  << ".0f" << endl;
        cout << "double: " << n  << ".0" << endl;
    }
}

void handleFloat(const string literal) {
    float nf;

    std::istringstream ss(literal);

    if (!(ss >> nf))
        cout << "this float conversion is impossible." << endl;
    else {
        int n = static_cast<int>(nf);
        cout << "char: ";
        if (n > 127)
            cout << "impossible" << endl;
        else if (n < ' ' || n > '~')
            cout << "Non displayable" << endl;
        else
            cout << "'" << (char)n << "'" << endl;

        cout << "int: ";
        if (nf < static_cast<float>(__INT_MAX__ * -1) || nf > static_cast<float>(__INT_MAX__))
            cout << "impossible" << endl;
        else 
            cout << static_cast<int>(nf) << endl;

        if (nf == n)
            cout << std::fixed << std::setprecision(1);
        cout << "float: " << nf << "f" << endl;
        cout << "double: " << static_cast<double>(nf) << endl;
    }
}

void handleDouble(const string literal) {
    double nd;

    std::istringstream iss(literal);

    if (!(iss >> nd))
        cout << "this double conversion is impossible." << endl;
    else {
        int n = static_cast<int>(nd);
        cout << "char: ";
        if (n > 127)
            cout << "impossible" << endl;
        else if (n < ' ' || n > '~')
            cout << "Non displayable" << endl;
        else
            cout << "'" << (char)n << "'" << endl;

        cout << "int: ";
        if (nd < static_cast<float>(__INT_MAX__ * -1) || nd > static_cast<float>(__INT_MAX__))
            cout << "impossible" << endl;
        else 
            cout << static_cast<int>(nd) << endl;
        
        if (nd == n)
            cout << std::fixed << std::setprecision(1);
        cout << "float: " << static_cast<float>(nd)  << "f" << endl;
        cout << "double: " << nd << endl;
    }
}
