

// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ 
//       ✩ 
//       ✩ 
//       ✩ 
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "PmergeMe.hpp"

//.......................................................................................................
//										Constructor - Destructor- copy				            		|
//.......................................................................................................
    PmergeMe::PmergeMe() {}

    PmergeMe::~PmergeMe() {}

    PmergeMe::PmergeMe(PmergeMe const &src)
    {
        *this = src;
    }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
    {
        if (this != &rhs)
        {
            _vec = rhs._vec;
            _deque = rhs._deque;
        }
        return *this;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================



//=======================================================================================================
//										  Utils				    							|
//=======================================================================================================
    void PmergeMe::parseInput(char** argv) //all in one
    {
        std::string allArgs;
        for (int i = 1; argv[i]; ++i) 
        {
            allArgs += argv[i];
            allArgs += " ";
        }
        parseInputString(allArgs);
    }

    void PmergeMe::parseInputString(const std::string& inputLine) {
        std::istringstream iss(inputLine);
        std::string token;
        bool first = true;
    
        while (iss >> token) 
        {
            // Vérifie que le token est composé uniquement de chiffres
            if (!first)
                _rawInputCleaned += " ";
            if (token.find_first_not_of("0123456789") != std::string::npos) //check le token entier si caracter valid selon ref
            {
                std::cerr <<LIGHT_RED<< "Error: Invalid input here: " <<RESET_COLOR<< token << std::endl;
                std::exit(EXIT_FAILURE);
            }
    
            long value = std::strtol(token.c_str(), NULL, 10);
    
            // Vérifie les bornes
            if (value < 0 || value > std::numeric_limits<int>::max()) 
            {
                std::cerr << "Error: Out of range '" << token << "'" << std::endl;
                std::exit(EXIT_FAILURE);
            }
    
            _vec.push_back(static_cast<int>(value));//met dans les containers
            _deque.push_back(static_cast<int>(value));
            _rawInputCleaned += token + " ";
            first = false;
        }
    
        if (_vec.empty()) 
        {
            std::cerr << "Error: No input numbers." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    
        // Optionnel : check de doublons
        if (!isDuplicateFree(_vec)) {
            std::cerr << "Error: Duplicate values found." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
    


//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================