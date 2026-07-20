#include "MutantStack.hpp"

using std::stack;

template <typename T>
MutantStack<T>::MutantStack() : stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : stack<T>(other)
{}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other)
{
    if (this != &other)
        stack<T>::operator=(other);
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return (stack<T>::c.rend());
}