#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    BitcoinExchange bitcoin;
    bitcoin.loadDatabase("data.csv");
    bitcoin.processInput(argv[1]);

    return 0;
}
