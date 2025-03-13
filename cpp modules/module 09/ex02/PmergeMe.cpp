#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **argv, int argc)
{
    this->_argc = argc;
    std::string nums[argc];

    for (size_t i = 0; argv[i]; ++i)
    {
        if (!argv[i][0])
            exit(1);
        nums[i] = argv[i];
    }

    for (size_t z = 0; z < static_cast<size_t>(argc); ++z)
    {
        for (size_t i = 0, size = nums[z].size(); i < size; ++i)
        {
            if (!std::isdigit(nums[z][i]))
                std::cout << "Syntax Error\n", exit(1);
        }
        lst.push_back(atoi(argv[z]));
    }
    lstForVec = lst;
}

PmergeMe::~PmergeMe(){}

std::list<int> &PmergeMe::getLst()
{
    return this->lst;
}

void    PmergeMe::print(std::list<int> lst)
{
    if (!lst.size())
        return ;
    for (std::list<int>::iterator it = lst.begin(), end = lst.end(); it != end; ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

int PmergeMe::pop_and_get(std::list<int> &_lst)
{
    if (!_lst.size())
        throw 0;

    int ret = *_lst.begin();
    _lst.pop_front();
    return ret;
}

void PmergeMe::mergelists()
{
    std::list<int>::iterator it1;
    std::list<int>::iterator end1;
    std::list<int>::iterator it2;
    std::list<std::list<int> >::iterator list2;

    list2 = ++(lists.begin());
    it1 = lists.begin()->begin();
    end1 = lists.begin()->end();
    while (list2->size())
    {
        it2 = (++lists.begin())->begin();
        it1 = std::lower_bound(lists.begin()->begin(), lists.begin()->end(), *it2);
        lists.begin()->insert(it1, *it2);
        list2->erase(it2);
    }
    lists.erase(list2);
}

void PmergeMe::mergevectors()
{
    std::vector<int>::iterator it1;
    std::vector<int>::iterator end1;
    std::vector<int>::iterator it2;
    std::vector<std::vector<int> >::iterator vector2;

    vector2 = ++(vectors.begin());
    it1 = vectors[0].begin();
    end1 = vectors[0].end();
    while (!vector2->empty())
    {
        it2 = vector2->begin();
        it1 = std::lower_bound(vectors.begin()->begin(), vectors.begin()->end(), *it2);
        it1 = vectors[0].insert(it1, *it2);
        ++it1;
        end1 = vectors[0].end();
        vector2->erase(it2);
    }
    vectors.erase(vector2);
}

void PmergeMe::sortvector()
{
    struct timeval start;
    struct timeval end;
    int sw;
    std::vector<int>::iterator n1;
    std::vector<int>::iterator n2;

    gettimeofday(&start, NULL);
    while (!lstForVec.empty())
    {
        std::vector<int> vc;
        try
        {
            vc.push_back(pop_and_get(lstForVec));
            vc.push_back(pop_and_get(lstForVec));
        }
        catch(int)
        {
            vectors.push_back(vc);
            break;
        }
        vectors.push_back(vc);

        n1 = vectors.back().begin();
        n2 = vectors.back().begin() + 1;
        if (*n1 > *n2)
        {
            sw = *n1;
            *n1 = *n2;
            *n2 = sw;
        }
    }
    while (vectors.size() > 1)
    {
        mergevectors();
    }
    gettimeofday(&end, NULL);
    std::cout << "Time to process a range of " << _argc << " elements with std::vector : ";
    std::cout << ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) << " us\n";
}

void PmergeMe::sortlist()
{
    struct timeval                          start;
    struct timeval                          end;
    int                                     sw;
    std::list<int>::iterator 				n1;
    std::list<int>::iterator 				n2;

    std::cout << "Before: ";
    print(lst);
    gettimeofday(&start, NULL);
    while (lst.size())
    {
        std::list<int>	lt;
        try
        {
            lt.push_back(pop_and_get(lst));
            lt.push_back(pop_and_get(lst));
        }
        catch(int){lists.push_back(lt); break;}
        lists.push_back(lt);

        n1 = (*lists.rbegin()).begin();
        n2 = ++(*lists.rbegin()).begin();
        if (*n1 > *n2)
        {
            sw = *n1;
            *n1 = *n2;
            *n2 = sw;
        }
    }
    while (lists.size() > 1)
    {
        mergelists();
    }
    gettimeofday(&end, NULL);
    std::cout << "After: ";
    print(*lists.begin());
    std::cout << "Time to process a range of " << _argc << " elements with std::list : ";
    std::cout << ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) << " us\n";
}
