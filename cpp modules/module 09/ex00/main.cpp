#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return std::cout << "Error with arguments" << std::endl, 1;
    BitcoinExchange btc(argv[1]);
    btc.PrintData();
	return 0;
}
