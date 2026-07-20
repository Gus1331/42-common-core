
#include "Span/Span.hpp"

Span::Span() : maxSize(0), size(0), v(vector<int>()) {
}

Span::Span(unsigned int size) : maxSize(size), size(0), v(vector<int>()) {
}

Span::Span(const Span &other) : maxSize(other.maxSize), size(other.size), v(vector<int>(other.v)) {
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->maxSize = other.maxSize;
        this->size = other.size;
        v = vector<int>(other.v);
    }
    return *this;
}

Span::~Span() {
}

/* Methods */
void Span::addNumber(int nbr) {
    if (size++ < maxSize)
        v.push_back(nbr);
    else
        throw MaxSpanCapacity();
}

int Span::shortestSpan() {
    if (size < 2) throw NoSpanFound();

    vector<int> sorted(v);
    sort(sorted.begin(), sorted.end());

    int minDiff = sorted[1] - sorted[0];

    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}

int Span::longestSpan() {
    if (size < 2) throw NoSpanFound();

    int min = *min_element(v.begin(), v.end());
    int max = *max_element(v.begin(), v.end());

    return max - min;
}
