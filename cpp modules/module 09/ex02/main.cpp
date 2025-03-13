#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        std::cout << "Not enough parameters\n";
        return 1;
    }
	PmergeMe whatever(argv + 1, argc - 1);
	whatever.sortlist();
    whatever.sortvector();
    return 0;
}
