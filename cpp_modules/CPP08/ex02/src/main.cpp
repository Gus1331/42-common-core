
#include "MutantStack/MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::list;

int main() {
    cout <<"1. Teste do Subject (MutantStack)" << endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    cout << "Top: " << mstack.top() << endl;
    mstack.pop();
    cout << "Size: " << mstack.size() << endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    cout << "Elementos da MutantStack:" << endl;
    while (it != ite)
        cout << *(it++) << endl;

    cout << endl << "2. Teste de Comparação (std::list)" << endl;
    
    list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    
    cout << "Top (back): " << lstack.back() << endl;
    lstack.pop_back();
    cout << "Size: " << lstack.size() << endl;
    
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    
    list<int>::iterator lit = lstack.begin();
    list<int>::iterator lite = lstack.end();
    
    ++lit;
    --lit;
    
    cout << "Elementos da std::list:" << endl;
    while (lit != lite)
    {
        cout << *lit << endl;
        ++lit;
    }

    cout << endl << "3. Testes Extras (Const iterators & Reverse iterators)" << endl;

    MutantStack<string> string_stack;
    string_stack.push("Um");
    string_stack.push("Dois");
    string_stack.push("Três");
    string_stack.push("Quatro");

    cout << "Iterando de trás para frente (Reverse):" << endl;
    MutantStack<string>::reverse_iterator rit = string_stack.rbegin();
    MutantStack<string>::reverse_iterator rite = string_stack.rend();
    while (rit != rite)
        cout << " - " << *rit++ << endl;

    cout << "Iterando com Const Iterator:" << endl;
    const MutantStack<string> const_stack(string_stack); 
    MutantStack<string>::const_iterator cit = const_stack.begin();
    MutantStack<string>::const_iterator cite = const_stack.end();
    while (cit != cite)
        cout << " -> " << *(cit++) << endl;

    return 0;
}

 /*  main's subject
int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    cout << mstack.top() << endl;
    mstack.pop();
    cout << mstack.size() << endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        cout << *it << endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}
 */

