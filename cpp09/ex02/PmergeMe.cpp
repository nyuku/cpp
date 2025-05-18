

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
            _deq = rhs._deq;
        }
        return *this;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void PmergeMe::sort()
{
    
    std::cout <<LIGHT_CYAN<< "Before: [ ";

    std::cout << _rawInputCleaned << "]";
    
    double TimerVector = benchmarkVector();
    double TimerDeque = benchmarkDeque();

    std::cout <<ENDL<<LIGHT_CYAN<< "After:  ";
    printContainerVector("", _vec);
    std::cout <<RESET_COLOR;
    // printContainerDeque("", _deq);
    printBenchmarkTime(TimerVector, "std::vector", _vec.size());
    printBenchmarkTime(TimerDeque, "std::deque", _deq.size());
}



//=======================================================================================================
//										  Printing				    			        				|
//=======================================================================================================
void PmergeMe::printStatusVector(const std::vector<int>& vec) const
{
    std::cout << LIGHT_CYAN << "Status of Vector: " << RESET_COLOR << "[ ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

void PmergeMe::printContainerVector(const std::string& prefix, const std::vector<int>& container) const
{
    std::cout << prefix;
    std::cout << "[ ";
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i];
        if (i != container.size() - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}
void PmergeMe::printBenchmarkTime(double timeUs, const std::string& containerName, size_t size) 
{
    std::cout << "Time to process a range of "
              << LIGHT_GREEN << size << RESET_COLOR
              << std::fixed << std::setprecision(5)
              << " elements with "
              << LIGHT_GREEN << containerName << RESET_COLOR
              << ": "
              << LIGHTPURPLE << timeUs << RESET_COLOR << " us" << std::endl;
}

//=======================================================================================================
//										  Utils				    				            			|
//=======================================================================================================
// bool PmergeMe::isDuplicateFreeVector(const std::vector<int>& input) const
// {
//     std::set<int> seen;
//     for (size_t i = 0; i < input.size(); ++i) {
//         if (seen.find(input[i]) != seen.end()) {
//             return false; 
//         }
//         seen.insert(input[i]);
//     }
//     return true; 
// }
    void PmergeMe::isDuplicateFreeVector()
    {
        std::set<int> uniqueSet;
        std::vector<int> uniqueVec;
    
        for (size_t i = 0; i < _vec.size(); ++i) {
            if (uniqueSet.insert(_vec[i]).second) {
                uniqueVec.push_back(_vec[i]);
            }
        }
    
        size_t removed = _vec.size() - uniqueVec.size();
        _vec = uniqueVec;
    
        if (removed > 0) {
            std::cerr << LIGHT_GREEN << "Info: Removed " << removed << " duplicate(s) from input." << RESET_COLOR << std::endl;
        }
    }

void PmergeMe::parseInput(char** argv) //all in one
    {
        std::string allArgs;
        for (int i = 1; argv[i]; ++i) 
        {
            allArgs += argv[i];
            allArgs += " ";
        }
        parseInputStringVector(allArgs);
        parseInputStringDeque(allArgs);
    }

    void PmergeMe::parseInputStringVector(const std::string& inputLine) 
    {
        std::istringstream iss(inputLine);
        std::string token;
        bool first = true;
        if (inputLine.empty()) 
        {
            std::cerr << "Error: Empty input." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        // if (inputLine.length() > 3000) 
        // {
        //     std::cerr <<LIGHT_RED<< "Error: Input too long." <<RESET_COLOR<< std::endl;
        //     std::exit(EXIT_FAILURE);
        // }
        if (inputLine.length() < 2) 
        {
            std::cerr <<LIGHT_RED<< "Error: Input too short to be sorted." <<RESET_COLOR<< std::endl;
            std::exit(EXIT_FAILURE);
        }
        while (iss >> token) 
        {

            if (!first)
                _rawInputCleaned += " ";
            if (token.find_first_not_of("0123456789") != std::string::npos) //check le token entier si caracter valid selon ref
            {
                std::cerr <<LIGHT_RED<< "Error: Invalid input here: " <<RESET_COLOR<< token << std::endl;
                std::exit(EXIT_FAILURE);
            }
    
            long value = std::strtol(token.c_str(), NULL, 10);
    
    
            if (value < 0 || value > std::numeric_limits<int>::max()) 
            {
                std::cerr << "Error: Out of range '" << token << "'" << std::endl;
                std::exit(EXIT_FAILURE);
            }
    
            _vec.push_back(static_cast<int>(value));//met dans les containers
            _rawInputCleaned += token + " ";
            first = false;
        }
    
        if (_vec.empty()) 
        {
            std::cerr << "Error: No input numbers." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        isDuplicateFreeVector();
        // if (!isDuplicateFreeVector(_vec)) 
        // {
        //     std::cerr <<LIGHT_RED<< "Error: Duplicate values found." << RESET_COLOR<< std::endl;
        //     std::exit(EXIT_FAILURE);
        // }
    }

    std::vector<size_t> PmergeMe::generateJacobsthalSequenceVector(size_t max)
    {
        std::vector<size_t> seq;
        if (max == 0)
            return seq;
    
        size_t J0 = 0;
        size_t J1 = 1;
    
        seq.push_back(J0);
        if (J1 < max)
            seq.push_back(J1);
    
        while (true)
        {
            size_t next = J1 + 2 * J0;
            if (next >= max)
                break;
    
            // Évite les doublons : on vérifie que next est différent du dernier élément inséré
            if (seq.empty() || next != seq.back())
                seq.push_back(next);
    
            J0 = J1;
            J1 = next;
        }
    
        return seq;
    }
    
    


//=======================================================================================================
//										   Timer- algo					    							|
//=======================================================================================================
    double PmergeMe::benchmarkVector()
    {
        clock_t start = clock();

        mergeInsertSortVector(_vec);

        clock_t end = clock();
        double timer = static_cast<double>(end - start) / CLOCKS_PER_SEC; //* 1000000.0; // us
        return timer;
     
    }


//=======================================================================================================
//										   Merge Insert Sort 										|           
//=======================================================================================================
    void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
    {
        if (vec.size() <= 1) return; // Si le vecteur est déjà trié ou vide, rien à faire

        // Étape 1 : Diviser le vecteur en deux moitiés
        std::vector<int> maxima;  // Pour stocker les plus grands de chaque paire
        std::vector<int> pending; // Pour stocker les éléments restants à insérer
    
        size_t i = 0;
        // Étape 1 : Séparer les paires
        while (i + 1 < vec.size())//s'il y a un next donc au moins 2element
        {
            if (vec[i] > vec[i + 1]) //on a un maxima en [i]
            {
                maxima.push_back(vec[i]);
                pending.push_back(vec[i + 1]);
            }
            else
            {
                maxima.push_back(vec[i + 1]);
                pending.push_back(vec[i]);
            }
            i += 2;
        }
        if (i < vec.size())
        pending.push_back(vec[i]);

        std::cout<<ENDL;
        // Étape 2 : Trier les maxima récursivement jusqu'à 1 élément
        if (maxima.size() > 1)
            recursiveSortVector(maxima);

        // Étape 3 : Insérer les autres éléments dans l'ordre optimisé
        insertWithJacobsthalVector(maxima, pending);

        // Étape 4 : Écraser vec avec la séquence triée finale
        vec = maxima;
    }

    void PmergeMe::recursiveSortVector(std::vector<int>& vec)
    {
        if (vec.size() <= 1)
            return;
        // Diviser le vecteur en deux moitiés 

        size_t mid = vec.size() / 2;

        std::vector<int> left(vec.begin(), vec.begin() + mid);
        std::vector<int> right(vec.begin() + mid, vec.end());

        // Tri récursif sur chaque moitié
        recursiveSortVector(left);
        recursiveSortVector(right);

        // Fusion des deux moitiés triées
        size_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size())
        {
            if (left[i] < right[j])
                vec[k++] = left[i++];
            else
                vec[k++] = right[j++];
        }

        while (i < left.size())
            vec[k++] = left[i++];
        while (j < right.size())
            vec[k++] = right[j++];
    }

void PmergeMe::insertWithJacobsthalVector(std::vector<int>& sorted, std::vector<int>& pending)
{
    std::vector<bool> inserted(pending.size(), false);
    size_t i = 0;
    if (pending.empty())
        return;

    std::vector<size_t> jacobsthalSeq = generateJacobsthalSequenceVector(pending.size());

    // On parcourt les indices dans l'ordre de la séquence de Jacobsthal
   

    for ( i = 0; i < jacobsthalSeq.size(); ++i)
    {
        size_t idx = jacobsthalSeq[i];
       
        if (idx >= pending.size())
            continue;

        int value = pending[idx];

        // Insertion par recherche binaire dans 'sorted'
        std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
        sorted.insert(it, value);
        inserted[idx] = true;

    }
    while(i < pending.size())
        {
           
            if (!inserted[i])
            {
                int value = pending[i];
                std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
                sorted.insert(it, value);
                inserted[i] = true;
            }
            i++;
        }

 
}



// // ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// // 		 ✩ Algo highlight
// // ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
// #include "PmergeMe.hpp"

// //.......................................................................................................
// //										Constructor - Destructor- copy				            		|
// //.......................................................................................................
//     PmergeMe::PmergeMe() {}

//     PmergeMe::~PmergeMe() {}

//     PmergeMe::PmergeMe(PmergeMe const &src)
//     {
//         *this = src;
//     }

// //.......................................................................................................
// //										    Opérator 													|
// //.......................................................................................................
//     PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
//     {
//         if (this != &rhs)
//         {
//             _vec = rhs._vec;
//             _deq = rhs._deq;
//         }
//         return *this;
//     }

// //=======================================================================================================
// //										   Fonctions membres											|
// //=======================================================================================================
// void PmergeMe::sort()
// {
    
//     std::cout <<LIGHT_CYAN<< "Before: "<<RESET_COLOR
//     ;

//     std::cout << LIGHT_CYAN << _rawInputCleaned << RESET_COLOR << std::endl;
    
//     benchmarkVector();
//     benchmarkDeque();

//     std::cout <<LIGHT_CYAN<< "After: "<<RESET_COLOR;
//     printContainerVector("", _vec);
//     // printContainerDeque("", _deq);
// }



// //=======================================================================================================
// //										  Printing				    			        				|
// //=======================================================================================================
// void PmergeMe::printStatusVector(const std::vector<int>& vec) const
// {
//     std::cout << LIGHT_CYAN << "Status of Vector: " << RESET_COLOR << "[ ";
//     for (size_t i = 0; i < vec.size(); ++i)
//     {
//         std::cout << vec[i];
//         if (i != vec.size() - 1)
//             std::cout << ", ";
//     }
//     std::cout << " ]" << std::endl;
// }

// void PmergeMe::printContainerVector(const std::string& prefix, const std::vector<int>& container) const
// {
//     std::cout << prefix;
//     std::cout << "[ ";
//     for (size_t i = 0; i < container.size(); ++i)
//     {
//         std::cout << container[i];
//         if (i != container.size() - 1)
//             std::cout << ", ";
//     }
//     std::cout << " ]" << std::endl;
// }

// //=======================================================================================================
// //										  Utils				    				            			|
// //=======================================================================================================
// bool PmergeMe::isDuplicateFreeVector(const std::vector<int>& input) const
// {
//     std::set<int> seen;
//     for (size_t i = 0; i < input.size(); ++i) {
//         if (seen.find(input[i]) != seen.end()) {
//             return false; 
//         }
//         seen.insert(input[i]);
//     }
//     return true; 
// }


// void PmergeMe::parseInput(char** argv) //all in one
//     {
//         std::string allArgs;
//         for (int i = 1; argv[i]; ++i) 
//         {
//             allArgs += argv[i];
//             allArgs += " ";
//         }
//         parseInputStringVector(allArgs);
//         parseInputStringDeque(allArgs);
//     }

//     void PmergeMe::parseInputStringVector(const std::string& inputLine) 
//     {
//         std::istringstream iss(inputLine);
//         std::string token;
//         bool first = true;
//         if (inputLine.empty()) 
//         {
//             std::cerr << "Error: Empty input." << std::endl;
//             std::exit(EXIT_FAILURE);
//         }
//         if (inputLine.length() > 3000) 
//         {
//             std::cerr <<LIGHT_RED<< "Error: Input too long." <<RESET_COLOR<< std::endl;
//             std::exit(EXIT_FAILURE);
//         }
//         if (inputLine.length() < 2) 
//         {
//             std::cerr <<LIGHT_RED<< "Error: Input too short to be sorted." <<RESET_COLOR<< std::endl;
//             std::exit(EXIT_FAILURE);
//         }
//         while (iss >> token) 
//         {

//             if (!first)
//                 _rawInputCleaned += " ";
//             if (token.find_first_not_of("0123456789") != std::string::npos) //check le token entier si caracter valid selon ref
//             {
//                 std::cerr <<LIGHT_RED<< "Error: Invalid input here: " <<RESET_COLOR<< token << std::endl;
//                 std::exit(EXIT_FAILURE);
//             }
    
//             long value = std::strtol(token.c_str(), NULL, 10);
    
    
//             if (value < 0 || value > std::numeric_limits<int>::max()) 
//             {
//                 std::cerr << "Error: Out of range '" << token << "'" << std::endl;
//                 std::exit(EXIT_FAILURE);
//             }
    
//             _vec.push_back(static_cast<int>(value));//met dans les containers
//             _rawInputCleaned += token + " ";
//             first = false;
//         }
    
//         if (_vec.empty()) 
//         {
//             std::cerr << "Error: No input numbers." << std::endl;
//             std::exit(EXIT_FAILURE);
//         }
    
//         if (!isDuplicateFreeVector(_vec)) 
//         {
//             std::cerr <<LIGHT_RED<< "Error: Duplicate values found." << RESET_COLOR<< std::endl;
//             std::exit(EXIT_FAILURE);
//         }
//     }

//     std::vector<size_t> PmergeMe::generateJacobsthalSequenceVector(size_t max)
//     {
//         std::vector<size_t> seq;
//         if (max == 0)
//             return seq;
    
//         size_t J0 = 0;
//         size_t J1 = 1;
    
//         seq.push_back(J0);
//         if (J1 < max)
//             seq.push_back(J1);
    
//         while (true)
//         {
//             size_t next = J1 + 2 * J0;
//             if (next >= max)
//                 break;
    
//             // Évite les doublons : on vérifie que next est différent du dernier élément inséré
//             if (seq.empty() || next != seq.back())
//                 seq.push_back(next);
    
//             J0 = J1;
//             J1 = next;
//         }
    
//         return seq;
//     }
    
    


// //=======================================================================================================
// //										   Timer- algo					    							|
// //=======================================================================================================
//     void PmergeMe::benchmarkVector()
//     {
//         clock_t start = clock();

//         mergeInsertSortVector(_vec);

//         clock_t end = clock();
//         double timer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // us

//         std::cout << "Time to process a range of " 
//                 <<LIGHT_GREEN
//                 << _vec.size() <<RESET_COLOR
//                 << std::fixed << std::setprecision(5)
//                 << " elements with "
//                 <<LIGHT_GREEN
//                 <<"std::vector "
//                 <<RESET_COLOR
//                 <<": " 
//                 <<LIGHTPURPLE
//                 << timer 
//                 <<RESET_COLOR
//                 << " us" << std::endl;
//     }


// //=======================================================================================================
// //										   Merge Insert Sort 										|           
// //=======================================================================================================
//     void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
//     {
//         if (vec.size() <= 1) return; // Si le vecteur est déjà trié ou vide, rien à faire

//         // Étape 1 : Diviser le vecteur en deux moitiés
//         std::vector<int> maxima;  // Pour stocker les plus grands de chaque paire
//         std::vector<int> pending; // Pour stocker les éléments restants à insérer
    
//         size_t i = 0;
//         // Étape 1 : Séparer les paires
//         while (i + 1 < vec.size())//s'il y a un next donc au moins 2element
//         {
//             if (vec[i] > vec[i + 1]) //on a un maxima en [i]
//             {
//                 maxima.push_back(vec[i]);
//                 pending.push_back(vec[i + 1]);
//             }
//             else
//             {
//                 maxima.push_back(vec[i + 1]);
//                 pending.push_back(vec[i]);
//             }
//             i += 2;
//         }
//         if (i < vec.size())
//         pending.push_back(vec[i]);

//         std::cout << "\n==========merge insert sort=============" << std::endl;
//         std::cout << "Pending(merge) : ";
//         printStatusVector(pending); 
//         std::cout << "Maxima(merge) : ";
//         printStatusVector(maxima); 
//         std::cout<<ENDL;
//         // Étape 2 : Trier les maxima récursivement jusqu'à 1 élément
//         if (maxima.size() > 1)
//             recursiveSortVector(maxima);

//         // Étape 3 : Insérer les autres éléments dans l'ordre optimisé
//         insertWithJacobsthalVector(maxima, pending);

//         // Étape 4 : Écraser vec avec la séquence triée finale
//         vec = maxima;
//     }

//     void PmergeMe::recursiveSortVector(std::vector<int>& vec)
//     {
//         if (vec.size() <= 1)
//             return;
//         // Diviser le vecteur en deux moitiés  
//         std::cout << "\n==========recursive SortVector=============" << std::endl; 
//         std::cout << "Before splitting: ";
//         printStatusVector(vec);

//         size_t mid = vec.size() / 2;

//         std::vector<int> left(vec.begin(), vec.begin() + mid);
//         std::vector<int> right(vec.begin() + mid, vec.end());

//         // Tri récursif sur chaque moitié
//         recursiveSortVector(left);
//         recursiveSortVector(right);

//         std::cout << "Left sorted: ";
//         printStatusVector(left);
//         std::cout << "Right sorted: ";
//         printStatusVector(right);

//         // Fusion des deux moitiés triées
//         size_t i = 0, j = 0, k = 0;
//         while (i < left.size() && j < right.size())
//         {
//             if (left[i] < right[j])
//                 vec[k++] = left[i++];
//             else
//                 vec[k++] = right[j++];
//         }

//         while (i < left.size())
//             vec[k++] = left[i++];
//         while (j < right.size())
//             vec[k++] = right[j++];
//         std::cout << "After merging: ";
//         printStatusVector(vec);
//     }

// void PmergeMe::insertWithJacobsthalVector(std::vector<int>& sorted, std::vector<int>& pending)
// {
//     std::vector<bool> inserted(pending.size(), false);
//     size_t i = 0;
//     if (pending.empty())
//         return;
//     std::cout << "\n========== insert Jacobsthal=============" << std::endl;

//     std::vector<size_t> jacobsthalSeq = generateJacobsthalSequenceVector(pending.size());
//     std::cout <<LIGHTPURPLE<< "Jacobsthal sequence: "<<RESET_COLOR;
//     for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
//     {
//         std::cout << jacobsthalSeq[i] << " ";
//     }
//     std::cout << std::endl;

//     // On parcourt les indices dans l'ordre de la séquence de Jacobsthal
   
//     std::cout << "Sorted avant(maxima): ";
//     printStatusVector(sorted);
//     std::cout << "Pending avant: ";
//     printStatusVector(pending); 

//     for ( i = 0; i < jacobsthalSeq.size(); ++i)
//     {
//         size_t idx = jacobsthalSeq[i];
       
//         if (idx >= pending.size())
//             continue;

//         int value = pending[idx];
//         std::cout <<LIGHT_CYAN<< "\nValue to insert from pending: " <<RESET_COLOR<< pending[idx] << LIGHT_CYAN<<", index: " <<RESET_COLOR<< idx << std::endl;
//         std::cout <<LIGHT_GREEN<< "after insert: "<<RESET_COLOR;

//         // Insertion par recherche binaire dans 'sorted'
//         std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
//         sorted.insert(it, value);
//         inserted[idx] = true;

//         std::cout <<ENDL<<LIGHT_CYAN<<"sorted: "<<RESET_COLOR;
//         printStatusVector(sorted);

//     }
//     while(i < pending.size())
//         {
//             std::cout<<"End of Jacobsthal sequence, insert remaining elements"<<std::endl;
//             if (!inserted[i])
//             {
//                 int value = pending[i];
//                 std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
//                 sorted.insert(it, value);
//                 inserted[i] = true;

//                 std::cout << "Inserted: " << value <<", round: "<<i<< std::endl;
//                 std::cout <<LIGHT_TURCOI<< "Sorted apres insertion: "<<RESET_COLOR;
//                 printStatusVector(sorted);
//                 std::cout <<LIGHT_TURCOI<< "Pending apres insertion: "<<RESET_COLOR;
//                 printStatusVector(pending);
//             }
//             i++;
//         }
//     std::cout <<LIGHT_MAGENTA<< "\nSorted final: "<<RESET_COLOR;
//     printStatusVector(sorted); 
//     std::cout<<std::endl;
 
// }
