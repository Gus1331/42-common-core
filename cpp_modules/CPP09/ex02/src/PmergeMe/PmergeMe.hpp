

#ifndef __PMERGEME_H__
#define __PMERGEME_H__

#include <deque>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <sys/time.h> 

using std::cout;
using std::endl;
using std::vector;
using std::deque;

class PmergeMe {
    private:
        PmergeMe();
        PmergeMe(PmergeMe &other);
        PmergeMe&operator=(PmergeMe &other);
        deque<int> dint;
        vector<int> vint;

        void vbinaryInsert(std::vector<int>& chain, int item, size_t bound);
        void dbinaryInsert(std::deque<int>& chain, int item, size_t bound);
        size_t getJacobsthal(size_t n);


    public:
        PmergeMe(int argc, char **argv);

        ~PmergeMe();

        /* Methods */
        void dsort(deque<int> *arr);
        void vsort(vector<int> *arr);

        /* Getters & Setters*/
};

#endif


