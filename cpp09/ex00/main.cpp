
#include "BitcoinExchange.hpp"


int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        std::cerr <<LIGHT_RED<< "Error: please add a file to convert." <<RESET_COLOR<< std::endl;
        return (1);
    }
    BitcoinExchange btc;
    std::cout << "\n==[DATE]========[VALUE] * [RATE]=======[RESULT]=============" << std::endl;
    std::ifstream input(argv[1]);//declaration du flux+ouverture du fichier
    if (!btc.checkFileOpen(input))
        return 1;
    btc.processFile(input);
        return 0;

    return 0;
}
