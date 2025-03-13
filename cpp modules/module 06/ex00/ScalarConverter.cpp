#include "ScalarConverter.hpp"
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string str)
{
    
	std::cout << std::fixed << std::setprecision(10);
	if (((str[0] > '9' && str[0] < '0') || str[0] == '-') || !str.length())
	{
		std::cout << "Error: Invalid Argument" << std::endl;
		return ;
	}
    double arg = std::strtod(str.c_str(), NULL);
	if (std::isnan(arg) || arg > 127 || arg < -128)
		std::cout << "char: " << "impossible" << std::endl;
	else if (static_cast<char>(arg) >= 32 &&  static_cast<char>(arg) < 127)
    	std::cout << "char: " << "'" << static_cast<char>(arg) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (std::isnan(arg) || arg > 2147483647 || arg < -2147483648)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(arg) << std::endl;
    std::cout << "float: " << static_cast<float>(arg) << 'f' << std::endl;
    std::cout << "double: " << arg << std::endl;
}
