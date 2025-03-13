#include "Data.hpp"

Data::Data() : somedata("Default data")
{}

Data::Data(std::string data) : somedata(data)
{}

std::string Data::getData() const
{
    return this->somedata;
}

Data::Data(Data &cpy)
{
    this->somedata = cpy.getData();
}

Data &Data::operator=(Data &cpy)
{
    this->somedata = cpy.getData();
    return *this;
}

Data::~Data(){}