#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc > 1 && argc < 3)
        ScalarConverter::convert(argv[1]);
    else
        std::cout << "More than 2 or less than 1 arguments detected" << std::endl;
}