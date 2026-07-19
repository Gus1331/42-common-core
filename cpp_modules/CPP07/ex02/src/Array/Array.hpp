

#ifndef __ARRAY_H__
#define __ARRAY_H__

# include <iostream>
# include <exception>

template <typename T>
class Array {
    private:
        T *array;
        unsigned int arrSize;
    public:
        Array();
        Array(unsigned int n);
        Array(Array &other);

        Array&operator=(Array &other);
        T &operator[](unsigned int i);
		T const &operator[](unsigned int i) const;

        ~Array();

        /* Methods */
        unsigned int size() const;

        /* Exceptions */
        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char *what() const throw() { return "Index out of bounds :("; };
        };
};

# include "Array/Array.tpp"

#endif


