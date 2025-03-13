#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, double> csv;
    std::string input_file;
    BitcoinExchange();
public:
    void PrintData();
    BitcoinExchange(char *input_file);
    BitcoinExchange(BitcoinExchange &cpy);
    BitcoinExchange &operator=(BitcoinExchange &cpy);
    ~BitcoinExchange();
};
