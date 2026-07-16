
#include "ScalarConverter/ScalarConverter.hpp"

int main(int argc, char **argv){

    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else {
        cout << "Bad usage" << endl;
        return 1;
    }
    
    //test errors
    // ScalarConverter::convert("Lorem");
    // cout << "----" << endl;
    // ScalarConverter::convert("");
    // cout << "----" << endl;
    // ScalarConverter::convert("&e");
    // cout << "----" << endl;
    // ScalarConverter::convert("0'");
    // cout << "----" << endl;
    // ScalarConverter::convert("0+");
    // cout << "----" << endl;
    // ScalarConverter::convert("-+");
    // cout << "----" << endl;
    // ScalarConverter::convert(".+");
    // cout << "----" << endl;
    // ScalarConverter::convert("+.");
    // cout << "----" << endl;
    // ScalarConverter::convert(".f");
    // cout << "----" << endl;
    // ScalarConverter::convert("a.");
    // cout << "----" << endl;
    // ScalarConverter::convert("a.f");
    // cout << "----" << endl;
    // ScalarConverter::convert("+.F");

    // test special chars
    // ScalarConverter::convert("inf");
    // cout << "----" << endl;
    // ScalarConverter::convert("inff");
    // cout << "----" << endl;
    // ScalarConverter::convert("-inf");
    // cout << "----" << endl;
    // ScalarConverter::convert("-inff");
    // cout << "----" << endl;
    // ScalarConverter::convert("+inff");
    // cout << "----" << endl;
    // ScalarConverter::convert("+inff");
    // cout << "----" << endl;
    // ScalarConverter::convert("nan");
    // cout << "----" << endl;
    // ScalarConverter::convert("nanf");

    // test char
    // ScalarConverter::convert("c");
    // cout << "----" << endl;
    // ScalarConverter::convert("~");
    // cout << "----" << endl;
    // ScalarConverter::convert("\t");
    // cout << "----" << endl;
    // ScalarConverter::convert("\r");
    // cout << "----" << endl;
    // ScalarConverter::convert(" ");

    // test int
    // ScalarConverter::convert("0");
    // cout << "----" << endl;
    // ScalarConverter::convert("9");
    // cout << "----" << endl;
    // ScalarConverter::convert("32");
    // cout << "----" << endl;
    // ScalarConverter::convert("126");
    // cout << "----" << endl;
    // ScalarConverter::convert("128");
    // cout << "----" << endl;
    // ScalarConverter::convert("-5");
    // cout << "----" << endl;
    // ScalarConverter::convert("-128");
    // cout << "----" << endl;
    // ScalarConverter::convert("2147483647"); // max
    // cout << "----" << endl;
    // ScalarConverter::convert("-2147483648"); // min
    // cout << "----" << endl;
    // ScalarConverter::convert("-2147483649"); // min - 1 (error)

    // test float
    // ScalarConverter::convert("0.5000f");
    // cout << "----" << endl;
    // ScalarConverter::convert("9.5000f");
    // cout << "----" << endl;
    // ScalarConverter::convert("32.5000f");
    // cout << "----" << endl;
    // ScalarConverter::convert("126.5000f");
    // cout << "----" << endl;
    // ScalarConverter::convert("128.f");
    // cout << "----" << endl;
    // ScalarConverter::convert("-5.0f");
    // cout << "----" << endl;
    // ScalarConverter::convert("-128.333333333333F");
    // cout << "----" << endl;
    // ScalarConverter::convert("340282346638528859811704183484516925440.999999999f");
    // cout << "----" << endl;
    // ScalarConverter::convert("-3.40282347f");

    // test double
    // ScalarConverter::convert("0.5000");
    // cout << "----" << endl;
    // ScalarConverter::convert("9.5000");
    // cout << "----" << endl;
    // ScalarConverter::convert("32.5000");
    // cout << "----" << endl;
    // ScalarConverter::convert("126.5000");
    // cout << "----" << endl;
    // ScalarConverter::convert("128.");
    // cout << "----" << endl;
    // ScalarConverter::convert("-5.0");
    // cout << "----" << endl;
    // ScalarConverter::convert("-128.333333333333");
    // cout << "----" << endl;
    // ScalarConverter::convert("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0");
    // cout << "----" << endl;
    // ScalarConverter::convert("-3.40282347");
    return 0;
}