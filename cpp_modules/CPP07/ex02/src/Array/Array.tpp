#ifndef __ARRAY_TPP__
# define __ARRAY_TPP__


template <typename T>
Array<T>::Array() : array(NULL), arrSize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), arrSize(n) {}

template <typename T>
Array<T>::Array(Array &other) : array(new T[other.arrSize]), arrSize(other.arrSize) {
    for (unsigned int i = 0; i < arrSize; i++)
        array[i] = other.array[i];
}

template <typename T>
Array<T>::~Array() {
    delete [] array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array &other) {
    if (this != &other) {
        delete [] array;
        arrSize = other.arrSize;
        array = new T[arrSize];
        for (unsigned int i = 0; i < arrSize; i++) {
            array[i] = other.array[i];
        }
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= arrSize)
        throw OutOfBoundsException();
    return array[i];
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const {
    if (i >= arrSize)
        throw OutOfBoundsException();
    return array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return this->arrSize;
}

#endif
