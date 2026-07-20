

#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__


#include <iostream>
#include <stack>

using std::stack;

template <class T>
class MutantStack : public std::stack<T> {
    private:
        
        public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack&operator=(MutantStack const &other);
        
        ~MutantStack();
        
        /* iterators */
        typedef typename stack<T>::container_type container;
        typedef typename stack<T>::container_type::iterator iterator;
        typedef typename stack<T>::container_type::const_iterator const_iterator;
        typedef typename stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack::iterator begin();
        MutantStack::const_iterator begin() const;
        MutantStack::iterator end();
        MutantStack::const_iterator end() const;

        MutantStack::reverse_iterator rbegin();
        MutantStack::const_reverse_iterator rbegin() const;
        MutantStack::reverse_iterator rend();
        MutantStack::const_reverse_iterator rend() const;
};

#include "MutantStack/MutantStack.tpp"

#endif


