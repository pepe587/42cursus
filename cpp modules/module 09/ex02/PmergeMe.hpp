#pragma once
#include <list>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

class PmergeMe
{
private:
    int _argc;
    std::list<int> lstForVec;
    std::list<int> lst;
    std::list<std::list<int> > lists;
    std::vector<std::vector<int> > vectors;
    PmergeMe();
public:
    PmergeMe(char **argv, int argc);
    ~PmergeMe();
    void    print(std::list<int> lst);
    std::list<int> &getLst();
    int pop_and_get(std::list<int> &_lst);
    void    mergelists();
    void    mergevectors();
    void sortlist();
    void sortvector();
};
