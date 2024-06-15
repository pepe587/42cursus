#include "Harl.hpp"

int main(void)
{
    std::string command;
    Harl        harl;
    
    while (command != "EXIT" || std::cin.eof())
    {
        std::cout << "Enter your level" << std::endl;
        std::cin >> command;
        harl.complain(command);
    }   
}