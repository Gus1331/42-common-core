
#include "Span/Span.hpp"
#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

int main() {
    Span sp = Span(10);

    vector<int> nbrs;
    nbrs.push_back(10);
    nbrs.push_back(20);
    nbrs.push_back(30);
    nbrs.push_back(40);

    sp.addNumber(nbrs);


    list<int> lst;
    lst.push_back(50);
    lst.push_back(60);

    sp.addNumber(lst);

    cout << "Shortest Span: " << sp.shortestSpan() << endl;
    cout << "Longest Span: " << sp.longestSpan() << endl;

    return 0;
}



/*   main's subject

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    cout << sp.shortestSpan() << endl;
    cout << sp.longestSpan() << endl;
    return 0;
}
*/

