#pragma once
#include <iostream>

class Data
{
private:
    std::string somedata;
public:
    Data();
    Data(std::string somedata);
    Data(Data &cpy);
    ~Data();
    std::string getData() const;
    Data &operator=(Data &cpy);
};
