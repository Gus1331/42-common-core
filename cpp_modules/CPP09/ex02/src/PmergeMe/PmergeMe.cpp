
#include "PmergeMe/PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        int p = atoi(argv[i]);
        vint.push_back(p);
        dint.push_back(p);
    }

    cout << " Before: ";
    for (std::vector<int>::iterator it = vint.begin();  it != vint.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    long long usv;
    long long usd;

    {
        struct timeval tv1;
        struct timeval tv2;
        gettimeofday(&tv1, NULL);
        this->dsort(&dint);
        gettimeofday(&tv2, NULL);

        usd = (long long)(tv2.tv_sec - tv1.tv_sec) * 1000000 + (tv2.tv_usec - tv1.tv_usec);

    }
    {
        struct timeval tv1;
        struct timeval tv2;
        gettimeofday(&tv1, NULL);
        this->vsort(&vint);
        gettimeofday(&tv2, NULL);

        usv = (long long)(tv2.tv_sec - tv1.tv_sec) * 1000000 + (tv2.tv_usec - tv1.tv_usec);
    }

    
    cout << " After:  ";
    for (std::deque<int>::iterator it = dint.begin();  it != dint.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "deque: " << usd << "us" << endl;
    cout << "vector: " << usv << "us" << endl;
}

PmergeMe::PmergeMe(PmergeMe &other){
    (void)other;
    //this->params = other.params;
}

PmergeMe &PmergeMe::operator=(PmergeMe &other) {
    if (this != &other) {
        (void)other;
        //this->params = other.params;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
}

/* Methods */
void PmergeMe::dsort(deque<int> *arr) {
    if ((*arr).size() <= 1)
        return;
    
    bool hasStraggler = ((*arr).size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = (*arr).back();
        (*arr).pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < (*arr).size(); i += 2) {
        int first = (*arr)[i];
        int second = (*arr)[i + 1];
        if (first < second) {
            std::swap(first, second);
        }
        pairs.push_back(std::make_pair(first, second));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    dsort(&mainChain);

    std::deque<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    size_t jacobIndex = 3;
    size_t lastInserted = 1;

    while (lastInserted < pend.size()) {
        size_t nextJacob = getJacobsthal(jacobIndex);
        size_t targetIndex = nextJacob - 1;

        if (targetIndex >= pend.size()) {
            targetIndex = pend.size() - 1;
        }

        for (size_t i = targetIndex; i >= lastInserted; --i) {
            dbinaryInsert(mainChain, pend[i], mainChain.size());
            if (i == lastInserted) break;
        }

        lastInserted = targetIndex + 1;
        jacobIndex++;
    }

    if (hasStraggler) {
        dbinaryInsert(mainChain, straggler, mainChain.size());
    }

    (*arr) = mainChain;

    (void)straggler;
}

void PmergeMe::vsort(vector<int> *arr) {
    if ((*arr).size() <= 1)
        return;

    bool hasStraggler = ((*arr).size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = (*arr).back();
        (*arr).pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < (*arr).size(); i += 2) {
        int first = (*arr)[i];
        int second = (*arr)[i + 1];
        if (first < second) {
            std::swap(first, second);
        }
        pairs.push_back(std::make_pair(first, second));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    vsort(&mainChain);

    std::vector<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    size_t jacobIndex = 3;
    size_t lastInserted = 1;

    while (lastInserted < pend.size()) {
        size_t nextJacob = getJacobsthal(jacobIndex);
        size_t targetIndex = nextJacob - 1;

        if (targetIndex >= pend.size()) {
            targetIndex = pend.size() - 1;
        }

        for (size_t i = targetIndex; i >= lastInserted; --i) {
            vbinaryInsert(mainChain, pend[i], mainChain.size());
            if (i == lastInserted) break;
        }

        lastInserted = targetIndex + 1;
        jacobIndex++;
    }

    if (hasStraggler) {
        vbinaryInsert(mainChain, straggler, mainChain.size());
    }

    (*arr) = mainChain;
}

size_t PmergeMe::getJacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t curr = 0;
    for (size_t i = 2; i <= n; ++i) {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

void PmergeMe::vbinaryInsert(std::vector<int>& chain, int item, size_t bound) {
    std::vector<int>::iterator endIt = chain.begin();
    if (bound < chain.size()) {
        std::advance(endIt, bound);
    } else {
        endIt = chain.end();
    }
    std::vector<int>::iterator pos = std::lower_bound(chain.begin(), endIt, item);
    chain.insert(pos, item);
}

void PmergeMe::dbinaryInsert(std::deque<int>& chain, int item, size_t bound) {
    std::deque<int>::iterator endIt = chain.begin();
    if (bound < chain.size()) {
        std::advance(endIt, bound);
    } else {
        endIt = chain.end();
    }
    std::deque<int>::iterator pos = std::lower_bound(chain.begin(), endIt, item);
    chain.insert(pos, item);
}

/* Getters & Setters*/



