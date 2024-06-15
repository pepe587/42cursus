#include <iostream>
#include <fstream>

void replace(std::string &str, std::string to_replace, std::string s2)
{
    int pos = 0;

    while (pos != -1)
    {
        pos = str.find(to_replace, pos);
        if (pos != -1)
        {
            str.erase(pos, to_replace.length());
            str.insert(pos, s2);
        }
    }
    
}

int main(int argc, char **argv)
{
    std::string file1;
    std::string replacestr;

    if (argc != 4)
        return (std::cout << "Error with args", 1);
    std::ifstream file(argv[1], std::ios::in);
    if (file.is_open())
    {
        std::ofstream filereplace(((std::string)"replace." + (std::string)argv[1]).c_str(), std::ios::out);;
        std::getline(file, file1, (char)-1);
        replace(file1, (std::string)argv[2], (std::string)argv[3]);
        filereplace << file1;
    }
    else
        std::cout << "error opening file" << std::endl;
}