#ifndef __EASYFIND_TPP__
#define __EASYFIND_TPP__

using std::find;

template <typename T>
typename T::value_type *easyfind(T &container, int n) {
    typename T::iterator it;

    it = find(container.begin(), container.end(), n);
    if (it != container.end())
        return &(*it);

    return 0;
}

#endif
