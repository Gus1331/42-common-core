

#ifndef __SPAN_H__
#define __SPAN_H__

#include <exception>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::min_element;
using std::max_element;

class Span {
    private:
        unsigned int maxSize;
        unsigned int size;
        vector<int> v;
        Span();

    public:
        Span(unsigned int size);
        Span(const Span &other);
        Span& operator=(const Span &other);

        ~Span();

        /* Methods */
        void addNumber(int nbr);
        int shortestSpan();
        int longestSpan();

        template <typename T>
        void addNumber(T &nbrs) {
            for (typename T::iterator it = nbrs.begin(); it != nbrs.end(); it++) {
                if (size >= maxSize) throw MaxSpanCapacity() ;
                this->v.push_back(*it);
                size++;
            }
        };

        /* Exceptions */
        class NoSpanFound : public std::exception {
            public:
                virtual const char *what() const throw() { return "There is no span to be found!"; }
        };

        class MaxSpanCapacity : public std::exception {
            public:
                virtual const char *what() const throw() { return "Max Span capacity achieved!"; }
        };
};

#endif


