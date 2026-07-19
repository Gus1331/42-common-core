#pragma once

#include <iostream>

template<typename T, typename F>
void iter(T *arr, size_t length, F &fun) {
    for (size_t i = 0; i < length; i++) {
        fun(arr[i]);
    }
}
