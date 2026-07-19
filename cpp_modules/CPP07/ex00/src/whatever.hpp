#pragma once

template<typename T>
void swap(T &p1, T &p2) {
    T temp = p1;
    p1 = p2;
    p2 = temp;
}

template<typename T>
T &min (T &p1, T &p2) {
    return (p1 < p2) ? p1 : p2;
}

template<typename T>
T &max (T &p1, T &p2) {
    return (p1 > p2) ? p1 : p2;
}
