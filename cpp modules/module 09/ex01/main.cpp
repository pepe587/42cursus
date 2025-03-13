#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return std::cout << "The program only needs one argument\n", 1;
    RPN rpn(argv[1]);
    rpn.PrintResult();
    return 0;
}