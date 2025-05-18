#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <list of positive integers>" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    // Parse l'input
    sorter.parseInput(argv);

    // Lance le tri et affiche avant/après
    sorter.sort();

    return 0;
}
