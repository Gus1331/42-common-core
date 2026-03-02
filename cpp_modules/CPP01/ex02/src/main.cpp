#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main (void) {
    string s = "HI THIS IS BRAIN";
    string *sp = &s;
    string &sr = s;

    cout << "var type		address" << endl;

    cout << "<string>		" << &s << endl;
    cout << "<string pointer>	" << sp << endl;
    cout << "<string reference>	" << &sr << endl;

    cout << endl << "var type		value" << endl;

    cout << "<string>		" << s << endl;
    cout << "<string pointer>	" << *sp << endl;
    cout << "<string reference>	" << sr << endl;
}
