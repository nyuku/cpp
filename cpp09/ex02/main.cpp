#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        for (int i = 1; i < argc; ++i)
        {
            const char* arg = argv[i];
            for (size_t j = 0; arg[j]; ++j)
            {
                if (arg[j] < '0' || arg[j] > '9')
                {
                    std::cerr << LIGHT_RED << "ERROR: invalid input " <<RESET_COLOR<< argv[1] 
                            << LIGHT_RED<< " , only positive integers are allowed" 
                            << RESET_COLOR << std::endl;
                    return 1;
                }
            }
        }
        if (argc == 1)
            std::cerr << LIGHT_RED<< "ERROR: please enter a list of positive integers more than 1" <<RESET_COLOR<< std::endl;
        else
            std::cerr <<LIGHT_RED<< "ERROR: Only " <<RESET_COLOR<< argv[1] <<LIGHT_RED<< "?  please enter a list of positive integers more than 1" <<RESET_COLOR<< std::endl;
        return 1;
    }

    PmergeMe sorter;

    // Parse l'input
    sorter.parseInput(argv);

    // Lance le tri et affiche avant/après
    sorter.sort();

    return 0;
}
