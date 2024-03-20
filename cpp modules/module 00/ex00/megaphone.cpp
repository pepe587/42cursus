#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int i = 0;
    int x = 1;


    std::string ret;
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    while (argv[x])
    {
        i = 0;
        while (argv[x][i])
        {
            ret.push_back(std::toupper(argv[x][i]));
            i++;
        }
        std::cout << ret;
        ret.clear();
        x++;
    }
    std::cout << "\n";
    return 0;
}