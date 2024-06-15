#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl        harl;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         i = 0;
    
    if (argc < 2)
        return (std::cout << "Error with the arguments" << std::endl, 1);
    while (i <= 3 && levels[i].compare(argv[1]))
        i++;
    while (i <= 3)
    {
        switch (i)
        {
            case 0:
                std::cout << "[DEBUG]" << std::endl;
                harl.complain((std::string)"DEBUG");
                break;

            case 1:
                std::cout << "[INFO]" << std::endl;
                harl.complain((std::string)"INFO");
                break;
    
            case 2:
                std::cout << "[WARNING]" << std::endl;
                harl.complain((std::string)"WARNING");
                break;

            case 3:
                std::cout << "[ERROR]" << std::endl;
                harl.complain((std::string)"ERROR");
                break;
        }
        i++;
    }
}