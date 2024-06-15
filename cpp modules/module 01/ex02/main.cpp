#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "MEMORY ADDRESS OF STRING: " << &string << std::endl;
    std::cout << "MEMORY ADDRESS OF STRINGPTR: " << &stringPTR << std::endl;
    std::cout << "MEMORY ADDRESS OF STRINGREF: " << &stringREF << std::endl;
    std::cout << "VALUE OF STRING: " << string << std::endl;
    std::cout << "VALUE OF STRINGPTR: " << *stringPTR << std::endl;
    std::cout << "VALUE OF STRINGREF: " << stringREF << std::endl;
}